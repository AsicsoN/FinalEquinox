#include "Battleship.h"
#include "ShipPawnBase.h"


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

	if (NavigationOfficer != nullptr)
	{
		//Initiative = NavigationOfficer->Piloting + FMath::RandRange(1, 20) + Speed;
	}

}

// Calculate ship stats
void AShipPawnBase::Instantiate(int32 Tactics)
{
	Initiative = NavigationOfficer->Piloting + FMath::RandRange(1, 20) + Speed;

	ActionPoints = NavigationOfficer->Piloting + Tactics + FMath::RandRange(1, 8) + PowerLevel;
	CurrentActionPoints = ActionPoints;

	MovementPoints = Speed + FMath::RandRange(1, 4) + Tactics;
	CurrentMovementPoints = MovementPoints;
}

// Called every frame
void AShipPawnBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AShipPawnBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

// Don't use this anymore
void AShipPawnBase::CalculateActionPoints(int32 Tactics)
{	
	/*ActionPoints = NavigationOfficer->Piloting + Tactics + FMath::RandRange(1, 8) + PowerLevel;
	CurrentActionPoints = ActionPoints;

	MovementPoints = Speed + FMath::RandRange(1, 4) + Tactics;
	CurrentMovementPoints = MovementPoints;*/
}