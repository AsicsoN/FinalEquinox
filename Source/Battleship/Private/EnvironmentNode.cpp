

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