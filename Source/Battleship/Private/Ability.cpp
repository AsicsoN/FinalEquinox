

#include "Battleship.h"
#include "Ability.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Animation/AnimMontage.h"
#include "ShipPawnBase.h"
#include "SpaceCombatGameMode.h"

FAbilityStruct::FAbilityStruct() 
	: Name(FText()), Description(FText()), Icon(nullptr), Animation(nullptr), ActionCost(0), Power(0.0f)
{

}

// Sets default values
AAbility::AAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
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
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(Instigator);

	if (!SelectedShip)
	{
		UE_LOG(LogTemp, Warning, TEXT("BANGBANG"));
		return;
	}

	// Check we have the Action Points
	if (SelectedShip->CurrentActionPoints >= Info.ActionCost)
	{
		if (Info.bIsTargeted && TargetShip)
		{
			TargettedAbility(TargetShip);
		}
		else if (Info.bAffectsAll || Info.AffectedDistance > 0)
		{
			AoeAbility();
		}
		else
		{
			SelfAbility();
		}

		SelectedShip->CurrentActionPoints -= Info.ActionCost;

		// Tick Ability
		TickAbility();

		// If no turns, immeadiately destroy i.e. instant buff
		if (!Info.NumberTurns)
		{
			Destroy();
		}
	}
}

void AAbility::TargettedAbility(AShipPawnBase* TargetShip)
{
	// TODO Extract and make GenerateBonus function
	if (Info.Type == EAbilityType::BUFF)
	{
		BoostStats(TargetShip);
		if (Info.NumberTurns > 1)
		{
			TargetShip->Buffs.Add(this);
		}
	}
	else
	{
		ReduceStats(TargetShip);
		if (Info.NumberTurns > 1)
		{
			TargetShip->Debuffs.Add(this);
		}
	}
}

void AAbility::AoeAbility()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(Instigator);

		if (SelectedShip)
		{
			float Distance = 256.0f * Info.AffectedDistance;

			// Find Affected Ships
			for (AShipPawnBase* Ship : GameMode->ShipArray)
			{
				if (Info.Type == EAbilityType::BUFF)
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

				if (Info.bAffectsAll || FVector::Dist(SelectedShip->GetActorLocation(), Ship->GetActorLocation()) <= Distance)
				{
					AffectedShips.Add(Ship);
				}
			}

			for (AShipPawnBase* Ship : AffectedShips)
			{
				if (Info.Type == EAbilityType::BUFF)
				{
					BoostStats(Ship);
					if (Info.NumberTurns > 1)
					{
						Ship->Buffs.Add(this);
					}
				}
				else
				{
					ReduceStats(Ship);
					if (Info.NumberTurns > 1)
					{
						Ship->Debuffs.Add(this);
					}
				}
			}
		}
	}	
}

void AAbility::SelfAbility()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(Instigator);

	if (SelectedShip)
	{
		// Apply Ability
		BoostStats(SelectedShip);

		// Remove Turn Point
		TickAbility();

		// Add Ability to Buffs
		if (Info.NumberTurns)
		{
			SelectedShip->Buffs.Add(this);
		}
	}
}

void AAbility::TickAbility()
{
	Info.NumberTurns--;
}

void AAbility::BoostStats(AShipPawnBase* Ship)
{
	float AffectedValue;

	if (Info.BuffType == EBuffType::SKILL)
	{
		float Power = Info.Power - 1.0f;
		switch (Info.AffectedSkill)
		{
			case EAbilitySkill::NAVIGATION:
				AffectedValue = Ship->Navigation * Power;
				Ship->Navigation += AffectedValue;
				break;
			case EAbilitySkill::ENGINEERING:
				AffectedValue = Ship->HullRepair * Power;
				Ship->HullRepair += AffectedValue;
				break;
			case EAbilitySkill::LEADERSHIP:
				AffectedValue = Ship->Leadership * Info.Power;
				Ship->Leadership += AffectedValue;
				break;
			case EAbilitySkill::TACTICS:
				AffectedValue = Ship->Tactics * Power;
				Ship->Tactics += AffectedValue;
				break;
			case EAbilitySkill::SCIENCE:
				AffectedValue = Ship->Science * Power;
				Ship->Science += AffectedValue;
				break;
			case EAbilitySkill::HIT:
				AffectedValue = Power;
				Ship->HitBonus += AffectedValue;
				break;
		}
	}
	else
	{
		AffectedValue = Info.Power;

		switch (Info.AffectedStat)
		{
			case EAbilityStat::HEALTH:
				Ship->CurrentHitPoints += Info.Power;
				break;
			case EAbilityStat::SHIELDS:
				Ship->CurrentShieldHitPoints += Info.Power;
				break;
			case EAbilityStat::SPEED:
				Ship->Speed += Info.Power;
				break;
			case EAbilityStat::ATTACK:
				Ship->AttackBonus += Info.Power;
				break;
		}
	}

	AffectedValues.Add(Ship, AffectedValue);
}

void AAbility::ReduceStats(AShipPawnBase* Ship)
{
	float AffectedValue;

	if (Info.BuffType == EBuffType::SKILL)
	{
		float Power = Info.Power - 1.0f;
		switch (Info.AffectedSkill)
		{
			case EAbilitySkill::NAVIGATION:
				AffectedValue = Ship->Navigation * Power;
				Ship->Navigation -= AffectedValue;
				break;
			case EAbilitySkill::ENGINEERING:
				AffectedValue = Ship->HullRepair * Power;
				Ship->HullRepair -= AffectedValue;
				break;
			case EAbilitySkill::LEADERSHIP:
				AffectedValue = Ship->Leadership * Info.Power;
				Ship->Leadership -= AffectedValue;
				break;
			case EAbilitySkill::TACTICS:
				AffectedValue = Ship->Tactics * Power;
				Ship->Tactics -= AffectedValue;
				break;
			case EAbilitySkill::SCIENCE:
				AffectedValue = Ship->Science * Power;
				Ship->Science -= AffectedValue;
				break;
			case EAbilitySkill::HIT:
				AffectedValue = Power;
				Ship->HitBonus -= AffectedValue;
				break;
		}
	}
	else
	{
		AffectedValue = Info.Power;

		switch (Info.AffectedStat)
		{
			case EAbilityStat::HEALTH:
				Ship->CurrentHitPoints -= Info.Power;
				break;
			case EAbilityStat::SHIELDS:
				Ship->CurrentShieldHitPoints -= Info.Power;
				break;
			case EAbilityStat::SPEED:
				Ship->Speed -= Info.Power;
				break;
			case EAbilityStat::ATTACK:
				Ship->AttackBonus -= Info.Power;
				break;
		}
	}

	AffectedValues.Add(Ship, AffectedValue);
}

void AAbility::Cleanup(AShipPawnBase* Ship)
{
	// If no value stored for this ship in ability, ignore - should never happen
	if (!AffectedValues.Contains(Ship))
	{
		return;
	}

	float AffectedValue = AffectedValues[Ship];

	// If it is a Buff, we need to reduce instead of buff
	if (Info.Type == EAbilityType::BUFF)
	{
		AffectedValue = -AffectedValue;
	}

	// Readjust values
	if (Info.BuffType == EBuffType::SKILL)
	{
		switch (Info.AffectedSkill)
		{
			case EAbilitySkill::NAVIGATION:
				Ship->Navigation += AffectedValue;
				break;
			case EAbilitySkill::ENGINEERING:
				Ship->HullRepair += AffectedValue;
				break;
			case EAbilitySkill::LEADERSHIP:
				Ship->Leadership += AffectedValue;
				break;
			case EAbilitySkill::TACTICS:
				Ship->Tactics += AffectedValue;
				break;
			case EAbilitySkill::SCIENCE:
				Ship->Science += AffectedValue;
				break;
			case EAbilitySkill::HIT:
				Ship->HitBonus += AffectedValue;
				break;
		}
	}
	else
	{
		switch (Info.AffectedStat)
		{
			case EAbilityStat::HEALTH:
				Ship->CurrentHitPoints += Info.Power;
				break;
			case EAbilityStat::SHIELDS:
				Ship->CurrentShieldHitPoints += Info.Power;
				break;
			case EAbilityStat::SPEED:
				Ship->Speed += Info.Power;
				break;
			case EAbilityStat::ATTACK:
				Ship->AttackBonus += Info.Power;
				break;
		}
	}

	// Remove Ship From Ability
	AffectedShips.Remove(Ship);

	if (!AffectedShips.Num())
	{
		SetLifeSpan(3.0f);
	}
}
