

#include "Battleship.h"
#include "Tile.h"
#include "GridLocation.h"
#include "SpaceCombatPlayerController.h"
#include "SpaceCombatGameMode.h"
#include "ShipPawnBase.h"
#include "AI/Navigation/NavigationPath.h"


// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Add Components
	Tile = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile"));
	Tile->SetupAttachment(RootComponent);

	RootComponent = Tile;

	Indicator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Indicator"));
	Indicator->SetupAttachment(Tile);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(Tile);
	
	// Bind Cursor Events
	Box->OnBeginCursorOver.AddDynamic(this, &ATile::CustomActorBeginCursorOver);
	Box->OnEndCursorOver.AddDynamic(this, &ATile::CustomActorEndCursorOver);

	GridLocation = CreateDefaultSubobject<UGridLocation>(TEXT("GridLocation"));
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::OnConstruction(const FTransform &Transform)
{
	// Set Grid Location
	FVector Location = GetActorLocation();

	float PosX = Location.X / 256;
	float PosY = Location.Y / 256;

	GridLocation->LocationX = FMath::RoundToInt(PosX);
	GridLocation->LocationY = FMath::RoundToInt(PosY);

	#if WITH_EDITOR
		SetFolderPath("Tiles");
	#endif
}

void ATile::CustomActorBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(GetWorld()->GetFirstPlayerController());
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());
	AShipPawnBase* SelectedShip = GameMode->SelectedShip;

	if (GameMode && PlayerController && GameMode->Phase == ESpaceCombatPhase::Combat)
	{
		if (PlayerController->bPreparingToMove && !PlayerController->bMoving && !PlayerController->bPreparingToFire)
		{
			// Set Tile Indicator Visible and Show Path
			Tile->SetVisibility(true);
			FlushPersistentDebugLines(GetWorld());
			BuildPath();
			PlayerController->Tile = this;

			if (SelectedShip != nullptr)
			{
				TArray<UStaticMeshComponent*> Components;
				SelectedShip->GetComponents<UStaticMeshComponent>(Components);
				if (Components.Num())
				{
					UStaticMeshComponent* StaticMeshComponent = Components[0];
					if (StaticMeshComponent) {
						UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
						StaticMeshComponent->SetWorldLocation(GetActorLocation(), true, nullptr, ETeleportType::TeleportPhysics);
					}
				}
			}
		}
	}
}

void ATile::CustomActorEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode != nullptr && GameMode->Phase == ESpaceCombatPhase::Combat)
	{
		ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(GetWorld()->GetFirstPlayerController());

		if (PlayerController->bPreparingToMove && !PlayerController->bMoving && !PlayerController->bPreparingToFire)
		{
			// Hide Path and Reset Tile
			Tile->SetVisibility(false);
			SetActorRotation(FRotator(0, 0, 0));
		}
	}
}

void ATile::BuildPath()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());
	AShipPawnBase* SelectedShip = GameMode->SelectedShip;

	// Get Start and End Points
	FVector Start = SelectedShip->GetActorLocation();
	FVector End = GetActorLocation();

	UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(GetWorld());

	// Calculate the AI Pathing using the Nav system.
	UNavigationPath *NavResult = NavSys->FindPathToLocationSynchronously(GetWorld(), Start, End, SelectedShip);

	// If not null, draw the path using the nav points provided
	if (NavResult != nullptr)
	{
		FColor LineColor = FColor();
		float PathLength = NavResult->GetPathLength();

		for (int32 Index = 0; Index < NavResult->PathPoints.Num(); Index++)
		{
			int32 NextIndex = Index + 1;
			bool bIsEven = (NextIndex % 2 > 0) ? true : false;

			NextIndex = FMath::Clamp(NextIndex, 1, FMath::RoundToInt(NavResult->PathPoints.Num() - 1));

			if (NextIndex != NavResult->PathPoints.Num())
			{
				FVector PointA = NavResult->PathPoints[Index];
				FVector PointB = NavResult->PathPoints[NextIndex];
				DrawDebugLine(
					GetWorld(), 
					PointA,
					PointB,
					LineColor.Cyan,
					true,
					-1,
					0,
					10.0f
				);
			}
		}

		// Draw the central dot in the circle
		DrawDebugLine(
			GetWorld(), 
			End, 
			End, 
			LineColor.Cyan,
			true, 
			-1, 
			0, 
			20.0f
		);

		// Calculate MP Path Cost
		PathLength = PathLength / 256;
		RequiredMP = FMath::RoundToInt(PathLength);
	}
}
