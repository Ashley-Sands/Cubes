// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerContr.generated.h"

class AMyCube;

UCLASS()
class MYPROJECT_API APlayerContr : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerContr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Category = "Cube", EditAnywhere)
		TSubclassOf<class AMyCube> bounceCube;
	
	UPROPERTY(Category = "Cube", EditAnywhere, BlueprintReadWrite)
		AMyCube* bounceCubeObj;

	UPROPERTY(Category = "Cube", EditAnywhere, BlueprintReadWrite)
	FVector spwanPosition;

	UPROPERTY(Category = "Cube", EditAnywhere, BlueprintReadWrite)
	FRotator spwanRotation;


private:

	void JumpAction();
};
