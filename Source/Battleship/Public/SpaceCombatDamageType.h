

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "SpaceCombatDamageType.generated.h"

/**
 * Default Type 
 */
UCLASS()
class BATTLESHIP_API USpaceCombatDamageType : public UDamageType
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FName DamageName;
	
};

UCLASS()
class BATTLESHIP_API UHullDamage : public USpaceCombatDamageType
{
	GENERATED_BODY()

	UHullDamage();


};

UCLASS()
class BATTLESHIP_API ULaserDamage : public USpaceCombatDamageType
{
	GENERATED_BODY()

	ULaserDamage();


};

UCLASS()
class BATTLESHIP_API UShieldDamage : public USpaceCombatDamageType
{
	GENERATED_BODY()

	UShieldDamage();


};

UCLASS()
class BATTLESHIP_API UMissileDamage : public USpaceCombatDamageType
{
	GENERATED_BODY()

	UMissileDamage();


};