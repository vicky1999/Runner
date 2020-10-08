// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSpawn.h"

// Sets default values for this component's properties
UObstacleSpawn::UObstacleSpawn()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UObstacleSpawn::BeginPlay()
{
	Super::BeginPlay();
	int ind=0;
	while(SpawnCount>0) {
		int Count=RowCount[FMath::RandRange(0,1)];
		FVector Location=Locations[FMath::RandRange(0,2)];
		FRotator Rotation=FRotator(0.f,90.f,0.f);
		for(int i=0;i<Count;i++) {
			AActor* Obs=GetWorld()->SpawnActor(Obstacle, &Location,&Rotation);
			Obs->AttachToComponent(this,FAttachmentTransformRules::KeepRelativeTransform,TEXT("Obstacle"));	
		}
		Locations[0].X+=pos;
		Locations[1].X+=pos;
		Locations[2].X+=pos;
		SpawnCount-=Count;
	}
	
}


// Called every frame
void UObstacleSpawn::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

