#include "Battleship.h"
#include "GridLocation.h"


// Sets default values for this component's properties
UGridLocation::UGridLocation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UGridLocation::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGridLocation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

int32 UGridLocation::GetXMin()
{
	int32 xmin = LocationX;

	if (Rotation == EGLRotation::Clockwise25)
	{
		xmin = LocationX - (Length - 1);
	}
	else if (Rotation == EGLRotation::Clockwise50)
	{
		xmin = LocationX - (Width - 1);
	}
	else if (Rotation == EGLRotation::Clockwise75)
	{
		xmin = LocationX;
	}

	return xmin;
}

int32 UGridLocation::GetXMax()
{
	int32 xmax = LocationX + Width - 1;

	if (Rotation == EGLRotation::Clockwise25)
	{
		xmax = LocationX;
	}
	else if (Rotation == EGLRotation::Clockwise50)
	{
		xmax = LocationX;
	}
	else if (Rotation == EGLRotation::Clockwise75)
	{
		xmax = LocationX + Length - 1;
	}

	return xmax;
}

int32 UGridLocation::GetYMin()
{
	int32 ymin = LocationY;

	if (Rotation == EGLRotation::Clockwise25)
	{
		ymin = LocationY;
	}
	else if (Rotation == EGLRotation::Clockwise50)
	{
		ymin = LocationY - (Length - 1);
	}
	else if (Rotation == EGLRotation::Clockwise75)
	{
		ymin = LocationY - (Width - 1);
	}

	return ymin;
}

int32 UGridLocation::GetYMax()
{
	int32 ymax = LocationY + Length - 1;

	if (Rotation == EGLRotation::Clockwise25)
	{
		ymax = LocationY + Width - 1;
	}
	else if (Rotation == EGLRotation::Clockwise50)
	{
		ymax = LocationY;
	}
	else if (Rotation == EGLRotation::Clockwise75)
	{
		ymax = LocationY;
	}

	return ymax;
}