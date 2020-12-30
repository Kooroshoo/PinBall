// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_PlayerController.generated.h"

class ABall;

UCLASS()
class PINBALL_API APaddle_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APaddle_PlayerController();
	
	UFUNCTION()
	virtual void SetupInputComponent() override;

protected:

	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);

	//Ball references

	void Launch();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> BallObj;

	ABall* MyBall;

	FVector SpawnLocation = FVector(10.f, 0.f, 40.f);
	FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;

public:
	void SpawnNewBall();




};
