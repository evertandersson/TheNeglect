#include "TriggerEvent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

ATriggerEvent::ATriggerEvent()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(Root);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATriggerEvent::HandleBeginOverlap);

	Triggered = false;

	PrimaryActorTick.bCanEverTick = false;
}

void ATriggerEvent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Triggered && OtherActor->IsA<ACharacter>())
	{
		EventIsTriggered();
		Triggered = true;
	}
}

