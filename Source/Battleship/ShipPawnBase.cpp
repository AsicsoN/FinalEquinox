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

void AShipPawnBase::Instantiate()
{
	
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

	bool ShieldsOnline = (Subsystems.ShieldGen != 0.0f);

	if (DamageEvent.DamageTypeClass->GetDefaultObjectName().ToString().Contains("ShieldDamage", ESearchCase::IgnoreCase))
	{
		if (ShieldsOnline && CurrentShieldHitPoints > 0)
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
	else if (DamageEvent.DamageTypeClass->GetDefaultObjectName().ToString().Contains("LaserDamage", ESearchCase::IgnoreCase) && ShieldsOnline)
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
	for (auto Buff : Buffs)
	{
		// Check for nullptr, remove from set
		if (!Buff)
		{
			continue;
		}

		if (!Buff->Info.NumberTurns)
		{
			Buff->Cleanup(this);
		}
		else
		{
			if (Buff->Instigator == this)
			{
				Buff->TickAbility();
			}
		}
	}
	Buffs.Remove(nullptr);

	// Check if any buffs have expired
	for (auto Debuff : Debuffs)
	{
		// Check for nullptr, remove from set
		if (!Debuff)
		{
			continue;
		}

		if (!Debuff->Info.NumberTurns)
		{
			Debuff->Cleanup(this);
		}
		else
		{
			if (Debuff->Instigator == this)
			{
				Debuff->TickAbility();
			}
		}
	}
	Debuffs.Remove(nullptr);
}