// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCube.generated.h"

UCLASS()
class MYPROJECT_API AMyCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Static mesh for pickup in level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Thing", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* objMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Thing", meta = (AllowPrivateAccess = "true"))
		float upForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape Thing", meta = (AllowPrivateAccess = "true"))
		bool applyForce;

	UFUNCTION(BlueprintCallable, Category = "Shape Thing")
		void ApplyObjForce();

	//UPROPERTY(Category = "Cube things", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//	StaticMeshActor* cube;
	//UPROPERTY(Category = "Cube things", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		//StaticMeshActor* MyCube;


};
