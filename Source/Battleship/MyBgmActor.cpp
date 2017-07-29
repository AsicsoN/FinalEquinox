

#include "Battleship.h"
#include "MyBgmActor.h"


// Sets default values
AMyBgmActor::AMyBgmActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyBgmActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBgmActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyBgmActor::SetVolume(AActor* BgmActor, float volume)
{
	if (BgmActor) {
		FString tempStr = BgmActor->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Actor: %s"), &tempStr);
		UE_LOG(LogTemp, Warning, TEXT("Volume: %f"), volume);
	}

}

