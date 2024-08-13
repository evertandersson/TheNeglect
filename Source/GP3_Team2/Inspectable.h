#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inspectable.generated.h"

class AGP3_Team2Character;

UCLASS()
class GP3_TEAM2_API AInspectable : public AActor
{
	GENERATED_BODY()
	
public:	
	AInspectable();

	void PickUpItem(AGP3_Team2Character* Player, USceneComponent* PickUpPoint);

	void InspectItem(float DeltaTime);

	void InteractWithItem();

	bool IsPickedUp;

	UPROPERTY(EditDefaultsOnly)
	bool IsInteractable;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void HandleRotation(float DeltaX, float DeltaY);

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root = nullptr;

	USceneComponent* PlayerPickUpPoint;

	float RotationSensitivity;

	float PickUpDistance;

	FVector OriginalPosition;
	FQuat OriginalRotation;

	UPROPERTY(EditAnywhere)
	float RotationSpeed;
};
