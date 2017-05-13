#include "Battleship.h"
#include "SpaceCombatGameMode.h"
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
}

// Calculate ship stats
void AShipPawnBase::Instantiate(int32 Tactics)
{
	Initiative = NavigationOfficer->Piloting + FMath::RandRange(1, 20) + Speed;

	ActionPoints = NavigationOfficer->Piloting + Tactics + FMath::RandRange(1, 8) + PowerLevel;
	CurrentActionPoints = ActionPoints;

	MovementPoints = Speed + FMath::RandRange(1, 4) + Tactics;
	CurrentMovementPoints = MovementPoints;

	CurrentHitPoints = HitPoints;
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
	// Call the base class - this will tell us how much damage to apply  
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	int32 damage = ActualDamage;

	CurrentHitPoints = CurrentHitPoints - damage;

	if (CurrentHitPoints <= 0)
	{
		ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->DestroyPawn(this);
	}

	return damage;
}

bool AShipPawnBase::IsTurnOver()
{
	if (CurrentMovementPoints <= 0 && CurrentActionPoints <= 0) return true;
	
	return ForceTurnEnd;
}