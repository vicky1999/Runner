// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleSpawn.h"
#include "Components/ChildActorComponent.h"
#include "Ground.generated.h"

UCLASS()
class INFINITERUNNER_API AGround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGround();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawner")
	UObstacleSpawn* Spawner;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
