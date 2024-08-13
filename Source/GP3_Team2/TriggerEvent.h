#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerEvent.generated.h"

class UBoxComponent;

UCLASS()
class GP3_TEAM2_API ATriggerEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	ATriggerEvent();

	virtual void EventIsTriggered() PURE_VIRTUAL(ATriggerEvent::EventIsTriggered);

protected:
	UFUNCTION()
	virtual void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool Triggered;

private:
	USceneComponent* Root = nullptr;
	
	UBoxComponent* BoxComponent = nullptr;
};
