#include "TriggerPlaySound.h"
#include "Kismet/GameplayStatics.h"

ATriggerPlaySound::ATriggerPlaySound()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ATriggerPlaySound::EventIsTriggered()
{
	if (ActorTarget && SoundToPlay)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SoundToPlay, ActorTarget->GetActorLocation());
	}
}


