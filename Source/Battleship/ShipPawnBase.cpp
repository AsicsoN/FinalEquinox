#include "Battleship.h"
#include "SpaceCombatGameMode.h"
#include "ShipPawnBase.h"

#define LOCTEXT_NAMESPACE "SpaceCombat" 

// Sets default values
AShipPawnBase::AShipPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShipPawnBase::BeginPlay()
{
	Super::BeginPlay();
}

// Calculate ship stats
void AShipPawnBase::Instantiate()
{
	Tactics = (Captain->Tactics * 0.4) + (TacticsOfficer->Tactics * 0.4) + (NavigationOfficer->Tactics * 0.2);
	Navigation = (NavigationOfficer->Navigation * 0.6) + (Captain->Navigation * 0.3) + (TacticsOfficer->Navigation * 0.1);
	Leadership = (Captain->Leadership * 0.6) + (TacticsOfficer->Leadership * 0.2) + (NavigationOfficer->Leadership * 0.2);
	Gunnery = (TacticsOfficer->Gunnery * 0.7) + (Captain->Gunnery * 0.3);
	Communication = (Captain->Communication * 0.5) + (NavigationOfficer->Communication * 0.25) + (TacticsOfficer->Communication * 0.25);
	ShieldRepair = (ScienceOfficer->ShieldRepair * 0.5) + (Engineer->ShieldRepair * 0.4) + (Captain->ShieldRepair * 0.1);
	HullRepair = (Engineer->Engineering * 0.8) + (Captain->Engineering * 0.2);
	SubsystemRepair = (Engineer->SubsystemRepair * 0.6) + (Captain->SubsystemRepair * 0.1) + (ScienceOfficer->SubsystemRepair * 0.3);
	Science = (ScienceOfficer->Science * 0.8) + (Captain->Science * 0.2);

	Initiative = Navigation + FMath::RandRange(1, 6) + Speed + Communication;
	Initiative = FMath::Clamp(Initiative, 0, 40);

	if (Type != EType::Small)
	{
		// Normal Ship Calculations
		ActionPoints = Tactics + FMath::RandRange(1, 8) + PowerLevel + Leadership + 4;
		ActionPoints = FMath::Clamp(ActionPoints, 0, 40);

		MovementPoints = Navigation + PowerLevel + FMath::RandRange(1, 8) + 4 + Tactics;
		MovementPoints = FMath::Clamp(MovementPoints, 0, 39);
	}
	else
	{
		// Fighter Calculation
		ActionPoints = FighterSkill + Tactics + FMath::RandRange(1, 6);
		ActionPoints = FMath::Clamp(ActionPoints, -3, 21);

		MovementPoints = FighterSkill + Communication + FMath::RandRange(1, 6);
		MovementPoints = FMath::Clamp(MovementPoints, -3, 21);
	}
	
	CurrentActionPoints = ActionPoints;
	CurrentMovementPoints = MovementPoints;

	CurrentHitPoints = HitPoints;
	CurrentShieldHitPoints = ShieldHitPoints;
}

// Called every frame
void AShipPawnBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AShipPawnBase::SetupPlayerInputComponent(class UInputComponent* InputComp)
{
	Super::SetupPlayerInputComponent(InputComp);
}

float AShipPawnBase::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());
	AShipPawnBase* DamageCauserPawn = Cast<AShipPawnBase>(DamageCauser);
	
	// Call the base class - this will tell us how much damage to apply  
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	int32 damage = ActualDamage;

	if (DamageEvent.DamageTypeClass->GetDefaultObjectName().ToString().Contains("ShieldDamage", ESearchCase::IgnoreCase))
	{
		if (CurrentShieldHitPoints > 0)
		{
			CurrentShieldHitPoints = CurrentShieldHitPoints - damage;

			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(damage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("TakeShieldDamage", "{Name} lost {Damage} shields due to being in an ion cloud."), Arguments));
		}
	}
	else if (DamageEvent.DamageTypeClass->GetDefaultObjectName().ToString().Contains("HullDamage", ESearchCase::IgnoreCase))
	{
		CurrentHitPoints = CurrentHitPoints - damage;

		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(*Name));
		Arguments.Add(TEXT("Damage"), FText::AsNumber(damage));

		ASpaceObject* DamageCauserObject = Cast<ASpaceObject>(DamageCauser);
		if (DamageCauserObject != nullptr)
		{
			Arguments.Add(TEXT("DamageCauser"), FText::FromString(DamageCauserObject->ObjectTypeDisplayName));
			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("HullDamageNamed", "A {DamageCauser} dealt {Damage} damage to {Name}."), Arguments));
		}
		else
		{
			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("HullDamage", "{Damage} damage was dealt to {Name}."), Arguments));
		}
	}
	else if (DamageEvent.DamageTypeClass->GetDefaultObjectName().ToString().Contains("LaserDamage", ESearchCase::IgnoreCase) && CurrentShieldHitPoints > 0)
	{
		CurrentShieldHitPoints = CurrentShieldHitPoints - damage;

		if (DamageCauserPawn != nullptr)
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("DamageCauser"), FText::FromString(DamageCauserPawn->Name));
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(damage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("DealShieldDamage", "{DamageCauser} dealt {Damage} shield damage to {Name}"), Arguments));
		}
		else
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(damage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("TakeShieldDamage", "{Name} was dealt {Damage} shield damage"), Arguments));
		}

		if (CurrentShieldHitPoints <= 0)
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("ShieldFailure", "Shield failure on {Name}"), Arguments));
		}
	}
	else
	{
		CurrentHitPoints = CurrentHitPoints - damage;

		if (DamageCauserPawn != nullptr)
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("DamageCauser"), FText::FromString(DamageCauserPawn->Name));
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(damage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("DealDamage", "{DamageCauser} dealt {Damage} damage to {Name}"), Arguments));
		}
		else
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(damage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("TakeDamage", "{Name} was dealt {Damage} damage"), Arguments));
		}

		if (CurrentHitPoints <= 0)
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("Destroyed", "{Name} has been destroyed"), Arguments));

			GameMode->DestroyPawn(this);
		}
	}

	return damage;
}

bool AShipPawnBase::IsTurnOver()
{
	if (CurrentMovementPoints <= 0 && CurrentActionPoints <= 0) return true;
	
	return ForceTurnEnd;
}

void AShipPawnBase::CheckExpiryBuffs()
{
	// Check if any buffs have expired
	for (auto Ability : Buffs)
	{
		if (!Ability->Info.NumberTurns)
		{
			Ability->Cleanup(this);
		}
		else
		{
			if (Ability->Instigator == this)
			{
				Ability->TickAbility();
			}
		}
	}

	// Check if any buffs have expired
	for (auto Ability : Debuffs)
	{
		if (!Ability->Info.NumberTurns)
		{
			Ability->Cleanup(this);
		}
		else
		{
			if (Ability->Instigator == this)
			{
				Ability->TickAbility();
			}
		}
	}
}