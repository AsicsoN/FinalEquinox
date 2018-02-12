

#include "Battleship.h"
#include "Ability.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Animation/AnimMontage.h"
#include "ShipPawnBase.h"
#include "SpaceCombatGameMode.h"

FAbilityStruct::FAbilityStruct() 
	: Name(""), Description(""), Icon(nullptr), Animation(nullptr), ActionCost(0), Power(0.0f)
{

}

// Sets default values
AAbility::AAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAbility::Execute(AShipPawnBase* TargetShip)
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		// Make sure Current Ship was the instigator 
		if (SelectedShip && Instigator == SelectedShip)
		{
			// Check we have the Action Points
			if (SelectedShip->CurrentActionPoints >= Info.ActionCost)
			{
				if (TargetShip)
				{
					TargettedAbility(TargetShip);
				}
				else if (Info.AffectedDistance > 0)
				{
					AoeAbility();
				}
				else
				{
					SelfAbility();
				}
			}
		}
	}
}

void AAbility::TargettedAbility(AShipPawnBase* TargetShip)
{
	// TODO Extract and make GenerateBonus function
	float Bonus = 0.0f;

	if (Info.BuffType == EBuffType::SKILL)
	{
		Bonus = Info.Power;
	}
	else
	{

	}

	// TODO Apply Bonus to Target Ship

	// Remove Turn from Ability
	TickAbility();

	// Add to Target Queue or Destroy
}

void AAbility::AoeAbility()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			float Distance = 256.0f * Info.AffectedDistance;

			// Find Affected Ships
			TArray<AShipPawnBase*> AffectedShips;
			for (auto Ship : GameMode->ShipArray)
			{
				if (Type == EAbilityType::BUFF)
				{
					if (SelectedShip->Faction != Ship->Faction)
					{
						continue;
					}
				}
				else
				{
					if (SelectedShip->Faction == Ship->Faction)
					{
						continue;
					}
				}

				if (FVector::Dist(SelectedShip->GetActorLocation(), Ship->GetActorLocation()) <= Distance)
				{
					AffectedShips.Add(Ship);
				}
			}

			// TODO Apply Bonus to each Target Ship

			// TODO Remove Turn from Ability

			// TODO Add to Targets' Queues or Destroy

		}
	}	
}

void AAbility::SelfAbility()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			// TODO Add Boost to Stats

			// TODO Add ability to TSet if Turn > 1
		}
	}
}

void AAbility::TickAbility()
{
	NumberTurns--;
};
