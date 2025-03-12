// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class SIMPLEPROTOTYPE_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	AFloorSwitch();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	TObjectPtr<class UBoxComponent> TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	TObjectPtr<class UStaticMeshComponent> FloorSwitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	TObjectPtr<UStaticMeshComponent> Door;

	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void RaiseSwitch();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void LowerSwitch();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void LowerDoor();

	UFUNCTION(BlueprintCallable, Category = "Floor Switch")
	void UpdateDoorLocation(float Z);

	UFUNCTION(BlueprintCallable, Category = "Floor Switch")
	void UpdateSwitchLocation(float Z);


	void CloseDoor();
protected:
	FTimerHandle SwitchTimerHandler;
	
	UPROPERTY(BlueprintReadWrite, Category = "Floor Switch")
	FVector InitDoorLocation;
	
	UPROPERTY(BlueprintReadWrite, Category = "Floor Switch")
	FVector InitSwitchLocation;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Floor Switch")
	float SwitchTimeDelay;

	bool bCharacterOnFloorSwitch;
};
