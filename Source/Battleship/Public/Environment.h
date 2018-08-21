

#pragma once

#include "CoreMinimal.h"

/**
 * Simple Data Storage class for storing level generation information
 */
class BATTLESHIP_API Environment
{
public:
	Environment();
	~Environment();

	float Asteroids;
	float IonCloud;
	float NochticGas;
	float SoverianGas;
	float SpaceshipWreckage;

};
