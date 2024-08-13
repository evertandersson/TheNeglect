#include "Inspectable.h"
#include "Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "GP3_Team2Character.h"

AInspectable::AInspectable()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	RotationSpeed = 1.0f;
	PickUpDistance = 40.f;

	PrimaryActorTick.bCanEverTick = true;
}

void AInspectable::BeginPlay()
{
	Super::BeginPlay();
	
	OriginalPosition = GetActorLocation();
	OriginalRotation = GetActorRotation().Quaternion();
}

void AInspectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	InspectItem(DeltaTime);
}

void AInspectable::PickUpItem(AGP3_Team2Character* Player, USceneComponent* PickUpPoint)
{
	if (!IsPickedUp)
	{
		PlayerPickUpPoint = PickUpPoint;
		IsPickedUp = true;
		Player->CanMove = false;
		return;
	}
	else 
	{
		PlayerPickUpPoint = nullptr;
		IsPickedUp = false;
		Player->CanMove = true;
		Player->InspectableObject = nullptr;
		return;
	}

}

void AInspectable::InspectItem(float DeltaTime)
{
	FVector CurrentPos;
	if (IsPickedUp && PlayerPickUpPoint)
	{
		CurrentPos = FMath::Lerp(PlayerPickUpPoint->GetComponentLocation(), GetActorLocation(), 0.5f);

		float DeltaX;
		float DeltaY;

		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(DeltaX, DeltaY);

		HandleRotation(DeltaX, DeltaY);
	}
	else
	{
		CurrentPos = FMath::Lerp(OriginalPosition, GetActorLocation(), 0.5f);

		FQuat CurrentRot = FMath::QInterpTo(OriginalRotation, GetActorRotation().Quaternion(), DeltaTime, 0.5f);

		SetActorRotation(CurrentRot);
	}

	SetActorLocation(CurrentPos);
}

void AInspectable::InteractWithItem()
{
	//Do something to the object
	UE_LOG(LogTemp, Display, TEXT("Changed inspectable object"));
}

void AInspectable::HandleRotation(float DeltaX, float DeltaY)
{
	FRotator Rotation = FRotator(-DeltaY * RotationSpeed, -DeltaX * RotationSpeed, 0.f);
	Rotation.Normalize();

	SetActorRotation(Rotation);
}
