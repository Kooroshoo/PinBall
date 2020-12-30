// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"
#include "Paddle_PlayerController.h"

APaddle_PlayerController::APaddle_PlayerController() 
{
	
}

void APaddle_PlayerController::BeginPlay()
{
	TArray<AActor*>CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();

}

void APaddle_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_PlayerController::MoveHorizontal); 
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_PlayerController::Launch);
}

void APaddle_PlayerController::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());
	if (MyPawn)
	{
		MyPawn->MoveHorizontal(AxisValue);
	}

}

void APaddle_PlayerController::Launch()
{
	MyBall->Launch();
}

void APaddle_PlayerController::SpawnNewBall()
{
	if (!MyBall)
	{
		MyBall = nullptr;
	}
	if (BallObj)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);
	}
}
