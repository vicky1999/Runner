// Fill out your copyright notice in the Description page of Project Settings.


#include "Ground.h"

// Sets default values
AGround::AGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshLoader(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	mesh->SetStaticMesh(MeshLoader.Object);

	ConstructorHelpers::FObjectFinder<UMaterial> MaterialLoader(TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Grime.M_Concrete_Grime'"));
	mesh->SetMaterial(0,MaterialLoader.Object);

	Spawner=CreateDefaultSubobject<UObstacleSpawn>(TEXT("ObstacleSpawner"));
	Spawner->SetupAttachment(mesh);
	
}

// Called when the game starts or when spawned
void AGround::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(20.f,10.f,1.f));	
}

// Called every frame
void AGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

