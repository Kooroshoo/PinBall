// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Paddle_PlayerController.h"
#include "Components/BoxComponent.h"
#include "BallBound.h"

// Sets default values
ABallBound::ABallBound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = BoxCollision;

}

// Called when the game starts or when spawned
void ABallBound::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABallBound::OnOverlapBegin);

	PlayerControllerRefrence = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void ABallBound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABallBound::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball"))
	{
		OtherActor->Destroy();
		PlayerControllerRefrence->SpawnNewBall();
	}
}



