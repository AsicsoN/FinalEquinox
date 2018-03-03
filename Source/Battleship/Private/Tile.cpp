

#include "Battleship.h"
#include "Tile.h"
#include "GridLocation.h"
#include "SpaceCombatPlayerController.h"
#include "SpaceCombatGameMode.h"
#include "ShipPawnBase.h"
#include "AI/Navigation/NavigationPath.h"
#include "Classes/Components/SplineComponent.h"
#include "Classes/Components/SplineMeshComponent.h"


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
					for (UStaticMeshComponent* StaticMeshComponent : Components)
					{
						if (StaticMeshComponent && StaticMeshComponent->ComponentHasTag(FName("Ship"))) 
						{
							StaticMeshComponent->SetWorldLocation(FVector(GetActorLocation().X, GetActorLocation().Y, StaticMeshComponent->GetComponentLocation().Z), true, nullptr, ETeleportType::TeleportPhysics);
						}
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
			ClearPath();
		}
	}
}

void ATile::BuildPath()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());
	ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(GetWorld()->GetFirstPlayerController());
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
		USplineComponent* Path = PlayerController->PathSpline;
		UStaticMesh* Mesh = PlayerController->LineMesh;

		FColor LineColor = FColor();
		float PathLength = NavResult->GetPathLength();

		Path->SetSplinePoints(NavResult->PathPoints, ESplineCoordinateSpace::Type::Local, true);

		for (int32 Index = 0; Index < Path->GetNumberOfSplinePoints() - 1; Index++)
		{
			USplineMeshComponent* Spline = NewObject<USplineMeshComponent>();

			FVector pointLocationStart, pointTangentStart, pointLocationEnd, pointTangentEnd;
			Path->GetLocalLocationAndTangentAtSplinePoint(Index, pointLocationStart, pointTangentStart);
			Path->GetLocalLocationAndTangentAtSplinePoint(Index + 1, pointLocationEnd, pointTangentEnd);

			if (Spline)
			{
				Spline->bCastDynamicShadow = false;
				Spline->SetStaticMesh(Mesh);
				Spline->SetStartAndEnd(pointLocationStart, pointTangentStart, pointLocationEnd, pointTangentEnd);
				Spline->RegisterComponentWithWorld(GetWorld());

				SplineMeshes.Add(Spline);
			}
		}

		// Calculate MP Path Cost
		PathLength = PathLength / 256;
		RequiredMP = FMath::RoundToInt(PathLength);
		if (SelectedShip->Type == EType::Large)
		{
			RequiredMP = RequiredMP * 2;
		}
	}
}

void ATile::ClearPath()
{
	ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(GetWorld()->GetFirstPlayerController());

	if (!PlayerController)
	{
		return;
	}

	USplineComponent* Path = PlayerController->PathSpline;

	if (!Path)
	{
		return;
	}

	while (SplineMeshes.Num())
	{
		USplineMeshComponent* Mesh = SplineMeshes.Pop(true);
		if (Mesh != nullptr && !Mesh->IsBeingDestroyed())
		{
			Mesh->DestroyComponent();
		}
	}

	Path->ClearSplinePoints(true);
}
