// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Obstacle.h"
#include "Engine/World.h"
#include "ObstacleSpawn.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INFINITERUNNER_API UObstacleSpawn : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObstacleSpawn();

	UPROPERTY(EditAnywhere,Category="SpawnCount")
	int SpawnCount=8;
	// the number of obstacles in a row
	TArray<int32> RowCount={1,2};
	TArray<FVector> Locations={FVector(-25.f,-36.f,0.f),FVector(-25.f,0.f,0.f),FVector(-25.f,36.f,0.f)};
	UPROPERTY(EditAnywhere,Category="SpawnCount")
	float pos=20.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Obstacles")
	TSubclassOf<AActor> Obstacle=AObstacle::StaticClass();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
