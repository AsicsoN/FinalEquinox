#include "Battleship.h"
#include "SpaceCombatGameMode.h"
#include "SpaceCombatPlayerController.h"
#include "ShipInfoBaseWidget.h"
#include "ShipPawnBase.h"

#define LOCTEXT_NAMESPACE "SpaceCombat" 

// Sets default values
AShipPawnBase::AShipPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Destructible
	Destructible = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Destructible Mesh"));
	Destructible->SetupAttachment(RootComponent);
	Destructible->bEditableWhenInherited = true;
	Destructible->SetSimulatePhysics(false);
	Destructible->SetEnableGravity(false);
	Destructible->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Destructible->SetLinearDamping(0.5f);

	// Setup Movement
	MovementSound = CreateDefaultSubobject<UAudioComponent>(TEXT("Movement Sound"));
	MovementSound->SetupAttachment(RootComponent);
	MovementSound->bAutoActivate = false;
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

	if (ShipInfoWidget)
	{
		ShipInfoWidget->Update();
	}

	if (bAdjustRotation)
	{
		Rotate(DeltaTime);
	}
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

	bool ShieldsOnline = (Subsystems.ShieldGen != 0.0f);

	if (DamageEvent.DamageTypeClass->GetName().Contains("ShieldDamage", ESearchCase::IgnoreCase))
	{
		if (ShieldsOnline && CurrentShieldHitPoints > 0)
		{
			CurrentShieldHitPoints = FMath::Clamp<float>(CurrentShieldHitPoints - ActualDamage, 0.0f, ShieldHitPoints);

			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(ActualDamage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("TakeShieldDamage", "{Name} lost {Damage} shields due to being in an ion cloud."), Arguments));
		}
	}
	else if (DamageEvent.DamageTypeClass->GetName().Contains("HullDamage", ESearchCase::IgnoreCase))
	{
		CurrentHitPoints = FMath::Clamp<float>(CurrentHitPoints - ActualDamage, 0.0f, HitPoints);

		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(*Name));
		Arguments.Add(TEXT("Damage"), FText::AsNumber(ActualDamage));

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
	else if (DamageEvent.DamageTypeClass->GetName().Contains("LaserDamage", ESearchCase::IgnoreCase) && ShieldsOnline)
	{
		CurrentShieldHitPoints = FMath::Clamp<float>(CurrentShieldHitPoints - ActualDamage, 0.0f, ShieldHitPoints);

		if (DamageCauserPawn != nullptr)
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("DamageCauser"), FText::FromString(DamageCauserPawn->Name));
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(ActualDamage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("DealShieldDamage", "{DamageCauser} dealt {Damage} shield damage to {Name}"), Arguments));
		}
		else
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(ActualDamage));

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
		CurrentHitPoints = FMath::Clamp<float>(CurrentHitPoints - ActualDamage, 0.0f, HitPoints);

		if (DamageCauserPawn != nullptr)
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("DamageCauser"), FText::FromString(DamageCauserPawn->Name));
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(ActualDamage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("DealDamage", "{DamageCauser} dealt {Damage} damage to {Name}"), Arguments));
		}
		else
		{
			FFormatNamedArguments Arguments;
			Arguments.Add(TEXT("Name"), FText::FromString(*Name));
			Arguments.Add(TEXT("Damage"), FText::AsNumber(ActualDamage));

			GameMode->WriteToCombatLog(FText::Format(LOCTEXT("TakeDamage", "{Name} was dealt {Damage} damage"), Arguments));
		}
	}

	if (CurrentHitPoints <= 0)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(*Name));
		GameMode->WriteToCombatLog(FText::Format(LOCTEXT("Destroyed", "{Name} has been destroyed"), Arguments));
	}

	return ActualDamage;
}

int32 AShipPawnBase::CalculateLaserDamage(bool CriticalHit)
{
	int32 Damage = FMath::RandRange(1, 20);

	if (CriticalHit)
	{
		Damage = Damage * 2;
	}
	
	return Damage;
}

int32 AShipPawnBase::CalculateMissileDamage(bool CriticalHit)
{
	int32 Damage = FMath::RandRange(1, 10);

	Damage += 10;

	if (CriticalHit)
	{
		Damage = Damage * 2;
	}

	return Damage;
}

void AShipPawnBase::Rotate(float DeltaTime)
{
	FRotator ShipRotation = GetActorRotation();

	// Rotate Pawn Progressively
	FRotator Rotation = FMath::RInterpTo(ShipRotation, NewRotation, DeltaTime, 4.0f);
	SetActorRelativeRotation(Rotation);

	// If nearly complete, snap rotation to fit
	if (Rotation.Equals(NewRotation, 1.0f))
	{
		SetActorRotation(FRotator(0, NewRotation.Yaw, 0));
		bAdjustRotation = false;
		if (MovementSound->IsPlaying())
		{
			MovementSound->FadeOut(0.5f, 0.0f);
		}
	}
}

void AShipPawnBase::CalculateFinalRotation(FVector Destination)
{
	FVector Location = GetActorLocation();

	float xDist = FMath::Abs(Location.X - Destination.X);
	float yDist = FMath::Abs(Location.Y - Destination.Y);

	if (xDist > yDist)
	{
		if (Location.X < Destination.X)
		{
			NewRotation.Yaw = 0;
		}
		else
		{
			NewRotation.Yaw = 180.0f;
		}
	}
	else
	{
		if (Location.Y < Destination.Y)
		{
			NewRotation.Yaw = 90;
		}
		else
		{
			NewRotation.Yaw = 270.0f;
		}
	}
}

bool AShipPawnBase::IsTurnOver()
{
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

void AShipPawnBase::ShipDestroyed()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	GameMode->ShipArray.Remove(this);

	TArray<UActorComponent*> Meshes = GetComponentsByTag(UStaticMeshComponent::StaticClass(), FName(TEXT("Ship")));

	if (Meshes.IsValidIndex(0))
	{
		UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(Meshes[0]);

		StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		StaticMesh->SetVisibility(false, true);

		Destructible->SetVisibility(true);
		Destructible->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		Destructible->SetCollisionProfileName(FName(TEXT("Destructible")));
		Destructible->SetSimulatePhysics(true);

		Destructible->ApplyDamage(100.0f, GetActorLocation(), FVector(0.0f), 1000.0f);

		for (const FFractureEffect Effect : Destructible->FractureEffects)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Effect.ParticleSystem, GetTransform());
			UGameplayStatics::SpawnSound2D(GetWorld(), Effect.Sound);
		}
	}

	if (ShipInfoWidget->IsValidLowLevel())
	{
		ShipInfoWidget->RemoveFromParent();
	}

	if (ShipIconWidget->IsValidLowLevel())
	{
		ShipIconWidget->RemoveFromParent();
	}

	GameMode->CheckCombatState();
}
