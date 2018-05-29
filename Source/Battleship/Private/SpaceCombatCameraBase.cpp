#include "Battleship.h"
#include "ShipPawnBase.h"
#include "SpaceCombatCameraBase.h"


// Sets default values
ASpaceCombatCameraBase::ASpaceCombatCameraBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceCombatCameraBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCombatCameraBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceCombatCameraBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASpaceCombatCameraBase::StartFollowingShip_Implementation(AShipPawnBase* TargetShip)
{

}

void ASpaceCombatCameraBase::StopFollowingShip_Implementation()
{

}
