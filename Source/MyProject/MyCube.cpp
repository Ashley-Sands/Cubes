// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCube.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyCube::AMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	objMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Physics"));
	objMesh->SetSimulatePhysics(true);
	//RootComponent = PickupMesh;
	SetRootComponent(objMesh);
	upForce = 13500.0f;

	applyForce = false;

}

// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (applyForce)
	{
		ApplyObjForce();
		applyForce = false;
	}
}

void AMyCube::ApplyObjForce()
{
	objMesh->AddImpulse(FVector(0, 0, upForce * objMesh->GetMass()));
}
