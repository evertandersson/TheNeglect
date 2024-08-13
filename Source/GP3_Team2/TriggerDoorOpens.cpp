#include "TriggerDoorOpens.h"

ATriggerDoorOpens::ATriggerDoorOpens()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATriggerDoorOpens::EventIsTriggered()
{
	UE_LOG(LogTemp, Display, TEXT("Door opens by trigger box!"));
	OpenDoor();
}



