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
	Navigation += (NavigationOfficer->Navigation / 100) * 60;
	Navigation += (Captain->Navigation / 100) * 30;
	Navigation += (TacticsOfficer->Navigation / 100) * 10;

	Communication += (Captain->Communication / 100) * 50;
	Communication += (NavigationOfficer->Communication / 100) * 25;
	Communication += (TacticsOfficer->Communication / 100) * 25;

	Leadership += (Captain->Leadership / 100) * 60;
	Leadership += (TacticsOfficer->Leadership / 100) * 20;
	Leadership += (NavigationOfficer->Leadership / 100) * 20;

	Tactics += (Captain->Tactics / 100) * 40;
	Tactics += (TacticsOfficer->Tactics / 100) * 40;
	Tactics += (NavigationOfficer->Tactics / 100) * 20;

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