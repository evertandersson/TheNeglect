#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerEvent.h"
#include "TriggerDoorOpens.generated.h"

UCLASS()
class GP3_TEAM2_API ATriggerDoorOpens : public ATriggerEvent
{
	GENERATED_BODY()
	
public:	
	ATriggerDoorOpens();

	void EventIsTriggered() override;

	//This function will run in the BP_TriggerDoorOpens
	UFUNCTION(BlueprintImplementableEvent, Category = "Door Events")
	void OpenDoor();
};
