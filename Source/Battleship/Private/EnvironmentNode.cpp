

#include "Battleship.h"
#include "EnvironmentNode.h"
#include "Environment.h"

void UEnvironmentNode::SetImage(UTexture2D* NewImage)
{ 
	Image = NewImage; 
}

UTexture2D* UEnvironmentNode::GetImage()
{
	return Image;
}

TArray<UEnvironmentNode*> UEnvironmentNode::GetChildren()
{
	return Children;
}

FString UEnvironmentNode::GetLaunchLevel()
{
	return LaunchLevel;
}

TSubclassOf<UUserWidget> UEnvironmentNode::GetLaunchWidget()
{
	return LaunchWidget;
}
