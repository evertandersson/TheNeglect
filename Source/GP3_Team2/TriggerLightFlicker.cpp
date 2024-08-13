#include "TriggerLightFlicker.h"

ATriggerLightFlicker::ATriggerLightFlicker()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ATriggerLightFlicker::EventIsTriggered()
{
	LightFlicker();
}
