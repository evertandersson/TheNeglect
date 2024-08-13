#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerEvent.h"
#include "TriggerLightFlicker.generated.h"

UCLASS()
class GP3_TEAM2_API ATriggerLightFlicker : public ATriggerEvent
{
	GENERATED_BODY()
	
public:	
	ATriggerLightFlicker();

	void EventIsTriggered() override;

	//This function will run in the BP_TriggerLightFlicker
	UFUNCTION(BlueprintImplementableEvent, Category = "Light Events")
	void LightFlicker();
};
