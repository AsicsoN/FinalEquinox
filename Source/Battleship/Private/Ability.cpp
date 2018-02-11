

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

void AAbility::TickAbility()
{
	LifeSpan--;

	MaybeCleanup();
};

void AAbility::MaybeCleanup()
{
	if (LifeSpan <= 0)
	{
		Destroy();
	}
}
