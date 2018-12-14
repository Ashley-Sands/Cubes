// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerContr.h"
#include "MyCube.h"
#include "Components/InputComponent.h"
#include "Engine.h"


// Sets default values
APlayerContr::APlayerContr()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bounceCube = CreateAbstractDefaultSubobject<AMyCube>(TEXT("Default"));
	spwanPosition = FVector(230, -170, 170);
	spwanRotation = FRotator(0, 0, 0);
}

// Called when the game starts or when spawned
void APlayerContr::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* world = GetWorld();
	if (world)
		bounceCubeObj = world->SpawnActor<AMyCube>(bounceCube, spwanPosition, spwanRotation);

}

// Called every frame
void APlayerContr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerContr::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &APlayerContr::JumpAction);

}

void APlayerContr::JumpAction()
{
	
	//if (scale == 0.0f) return;
	if (bounceCube == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, "NULL");
		return;
	}
	
 	bounceCubeObj->ApplyObjForce();
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, "Jump");
}
