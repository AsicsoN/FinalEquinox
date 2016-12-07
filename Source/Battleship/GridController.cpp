#include "Battleship.h"
#include "GridController.h"

// Sets default values
AGridController::AGridController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGridController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGridController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AGridController::GetSquareId(int32 x, int32 y)
{
	int32 toReturn = 0;

	toReturn = (SizeX * (y - 1)) + x;

	return toReturn;
}

bool AGridController::IsSquareOccupied(AShipPawnBase* ship, int32 x, int32 y)
{
	FString shipName = ship->GetName();
	UE_LOG(LogTemp, Error, TEXT("ShipName: %s"), *shipName);

	for (TActorIterator<AShipPawnBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (!shipName.Equals(ActorItr->GetName()))
		{
			UE_LOG(LogTemp, Error, TEXT("Found ShipPawn %s"), *ActorItr->GetName());
			UGridLocation* loc = ActorItr->FindComponentByClass<UGridLocation>();

			for (int xtile = loc->GetXMin(); xtile <= loc->GetXMax(); xtile++)
			{
				for (int ytile = loc->GetYMin(); ytile <= loc->GetYMax(); ytile++)
				{
					if (xtile == x && ytile == y)
					{
						return true;
					}
				}
			}			
		}
	}

	return false;
}

bool AGridController::IsSquareOutOfBounds(int32 x, int32 y)
{
	if (x < 1 || y < 1 || x > SizeX || y > SizeY)
	{
		return true;
	}
	return false;
}

bool AGridController::IsPositionValid(AShipPawnBase* ship, int32 x, int32 y, int32 width, int32 length, EGLRotation rotation)
{
	int32 xmin = x;
	int32 ymin = y;
	int32 xmax = x + width - 1;
	int32 ymax = y + length - 1;

	if (rotation == EGLRotation::Clockwise25)
	{
		xmin = x - (length - 1);
		ymin = y;
		xmax = x;
		ymax = y + width - 1;
	}
	else if (rotation == EGLRotation::Clockwise50)
	{
		xmin = x - (width - 1);
		ymin = y - (length - 1);
		xmax = x;
		ymax = y;
	}
	else if (rotation == EGLRotation::Clockwise75)
	{
		xmin = x;
		ymin = y - (width - 1);
		xmax = x + length - 1;
		ymax = y;
	}

	for (int xtile = xmin; xtile <= xmax; xtile++)
	{
		for (int ytile = ymin; ytile <= ymax; ytile++)
		{
			if (IsSquareOutOfBounds(xtile, ytile))
			{
				UE_LOG(LogTemp, Error, TEXT("xtile: %d ytile: %d out of bounds"), xtile, ytile);
				return false;
			}
			else if (IsSquareOccupied(ship, xtile, ytile))
			{
				UE_LOG(LogTemp, Error, TEXT("xtile: %d ytile: %d is occupied"), xtile, ytile);
				return false;
			}
		}
	}

	return true;
}

int32 AGridController::ConvertPositionToSquareId(FVector position)
{
	int32 x = (int32)position.X / Multiplier;
	int32 y = (int32)position.Y / Multiplier;

	return GetSquareId(x, y);
}

FVector AGridController::ConvertSquareIdToPosition(int32 x, int32 y)
{
	FVector pos = FVector(x * Multiplier, y * Multiplier, 0.0f);
	return pos;
}

void AGridController::Move(AShipPawnBase* ship, int32 direction)
{
	UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();
	int32 newLocationX = loc->LocationX;
	int32 newLocationY = loc->LocationY;

	if (direction == 3 || direction == 6 || direction == 9)
	{
		newLocationX++;
	}
	if (direction == 1 || direction == 4 || direction == 7)
	{
		newLocationX--;
	}
	if (direction == 7 || direction == 8 || direction == 9)
	{
		newLocationY--;
	}
	if (direction == 1 || direction == 2 || direction == 3)
	{
		newLocationY++;
	}

	if (IsPositionValid(ship, newLocationX, newLocationY, loc->Width, loc->Length, loc->Rotation))
	{
		loc->LocationX = newLocationX;
		loc->LocationY = newLocationY;
		FVector newLocationVector = FVector(newLocationX * Multiplier, newLocationY * Multiplier, 0.0f);
		ship->SetActorLocation(newLocationVector);
	}
}

gridLocation AGridController::CalculateClockwiseRotation(AShipPawnBase* ship)
{
	UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();
	int32 incrementAmount = loc->Length - 1;

	gridLocation newGridLocation;
	newGridLocation.x = loc->LocationX;
	newGridLocation.y = loc->LocationY;
	newGridLocation.rotation = loc->Rotation;

	if (loc->Rotation == EGLRotation::Normal)
	{
		newGridLocation.rotation = EGLRotation::Clockwise25;
		newGridLocation.x += incrementAmount;
	}
	else if (loc->Rotation == EGLRotation::Clockwise25)
	{
		newGridLocation.rotation = EGLRotation::Clockwise50;
		newGridLocation.y += incrementAmount;
	}
	else if (loc->Rotation == EGLRotation::Clockwise50)
	{
		newGridLocation.rotation = EGLRotation::Clockwise75;
		newGridLocation.x -= incrementAmount;
	}
	else if (loc->Rotation == EGLRotation::Clockwise75)
	{
		newGridLocation.rotation = EGLRotation::Normal;
		newGridLocation.y -= incrementAmount;
	}

	return newGridLocation;
}

bool AGridController::CanRotateClockwise(AShipPawnBase* ship)
{	
	gridLocation newLocation = CalculateClockwiseRotation(ship);
	UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();

	if (IsPositionValid(ship, newLocation.x, newLocation.y, loc->Width, loc->Length, newLocation.rotation))
	{
		return true;
	}
	return false;
}

void AGridController::RotateClockwise(AShipPawnBase* ship)
{	
	if (CanRotateClockwise(ship))
	{
		gridLocation newLocation = CalculateClockwiseRotation(ship);
		UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();

		FVector newLocationVector = FVector(newLocation.x * Multiplier, newLocation.y * Multiplier, 0.0f);
		ship->SetActorLocation(newLocationVector);
		loc->Rotation = newLocation.rotation;
		loc->LocationX = newLocation.x;
		loc->LocationY = newLocation.y;
		float newYaw = 0.0f;
		if (loc->Rotation == EGLRotation::Clockwise25) newYaw = 90.0f;
		else if (loc->Rotation == EGLRotation::Clockwise50) newYaw = 180.0f;
		else if (loc->Rotation == EGLRotation::Clockwise75) newYaw = -90.0f;
		FRotator newRotator = FRotator(0.0f, newYaw, 0.0f);
		ship->SetActorRotation(newRotator);
	}
}

gridLocation AGridController::CalculateCounterClockwiseRotation(AShipPawnBase* ship)
{
	UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();
	int32 incrementAmount = loc->Length - loc->Width;
	int32 adjustmentAmount = loc->Width - 1;

	gridLocation newGridLocation;
	newGridLocation.x = loc->LocationX;
	newGridLocation.y = loc->LocationY;
	newGridLocation.rotation = loc->Rotation;

	if (loc->Rotation == EGLRotation::Normal)
	{
		newGridLocation.rotation = EGLRotation::Clockwise75;
		newGridLocation.x -= incrementAmount;
		newGridLocation.y += adjustmentAmount;
	}
	else if (loc->Rotation == EGLRotation::Clockwise25)
	{
		newGridLocation.rotation = EGLRotation::Normal;
		newGridLocation.x -= adjustmentAmount;
		newGridLocation.y -= incrementAmount;
	}
	else if (loc->Rotation == EGLRotation::Clockwise50)
	{
		newGridLocation.rotation = EGLRotation::Clockwise25;
		newGridLocation.x += incrementAmount;
		newGridLocation.y -= adjustmentAmount;
	}
	else if (loc->Rotation == EGLRotation::Clockwise75)
	{
		newGridLocation.rotation = EGLRotation::Clockwise50;
		newGridLocation.x += adjustmentAmount;
		newGridLocation.y += incrementAmount;
	}

	return newGridLocation;
}

bool AGridController::CanRotateCounterClockwise(AShipPawnBase* ship)
{
	gridLocation newLocation = CalculateCounterClockwiseRotation(ship);
	UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();

	if (IsPositionValid(ship, newLocation.x, newLocation.y, loc->Width, loc->Length, newLocation.rotation))
	{
		return true;
	}
	return false;
}

void AGridController::RotateCounterClockwise(AShipPawnBase* ship)
{
	if (CanRotateCounterClockwise(ship))
	{
		gridLocation newLocation = CalculateCounterClockwiseRotation(ship);
		UGridLocation* loc = ship->FindComponentByClass<UGridLocation>();

		FVector newLocationVector = FVector(newLocation.x * Multiplier, newLocation.y * Multiplier, 0.0f);
		ship->SetActorLocation(newLocationVector);
		loc->Rotation = newLocation.rotation;
		loc->LocationX = newLocation.x;
		loc->LocationY = newLocation.y;
		float newYaw = 0.0f;
		if (loc->Rotation == EGLRotation::Clockwise25) newYaw = 90.0f;
		else if (loc->Rotation == EGLRotation::Clockwise50) newYaw = 180.0f;
		else if (loc->Rotation == EGLRotation::Clockwise75) newYaw = -90.0f;
		FRotator newRotator = FRotator(0.0f, newYaw, 0.0f);
		ship->SetActorRotation(newRotator);
	}
}