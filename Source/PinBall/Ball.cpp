// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;
	
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.X = 0.0f;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

void ABall::Launch()
{
	if (!BallLaunched)
	{
		SM_Ball->AddImpulse(FVector(340.f, 0.f, 340), FName(), true);
		BallLaunched = true;
	}
}
