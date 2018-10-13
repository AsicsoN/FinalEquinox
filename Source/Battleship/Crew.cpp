

#include "Battleship.h"
#include "Crew.h"
#include "MoraleSystem.h"

UCrew::UCrew()
{
	Morale.General = 6;
}

int32 UCrew::GetCurrentMorale()
{
	TArray<int32> MoraleLevels;
	MoraleLevels.Push(Morale.General);
	MoraleLevels.Push(Morale.Respect);
	MoraleLevels.Push(Morale.Love);
	MoraleLevels.Push(Morale.Fear);

	// Sort Array
	MoraleLevels.Sort([](const int32 a, const int32 b){
		return a > b;
	});

	return (MoraleLevels[0] * 2) + MoraleLevels[1] + MoraleLevels[2] + MoraleLevels[3];
}

FString UCrew::GetMoraleDescriptor(int32 MoraleLevel)
{
	return MoraleSystem::GetMoraleDescriptor(MoraleLevel);
}
