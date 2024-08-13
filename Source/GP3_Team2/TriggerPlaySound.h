#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerEvent.h"
#include "TriggerPlaySound.generated.h"

UCLASS()
class GP3_TEAM2_API ATriggerPlaySound : public ATriggerEvent
{
	GENERATED_BODY()
	
public:	
	ATriggerPlaySound();

	void EventIsTriggered() override;

	//Actor to play the sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	AActor* ActorTarget;

	//Sound effect to play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* SoundToPlay;
};
