// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"


// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh
	mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshLoader(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mesh->SetStaticMesh(MeshLoader.Object);
	ConstructorHelpers::FObjectFinder<UMaterial> MaterialLoader(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Basalt.M_Rock_Basalt'"));
	mesh->SetMaterial(0,MaterialLoader.Object);
	mesh->SetupAttachment(RootComponent);

		// Handling Collisions...
	// SphereRadius=200.f;
	// Collision=CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	// Collision->InitSphereRadius(SphereRadius);
	// Collision->SetCollisionProfileName("Collider");
	// RootComponent=Collision;
	Collision=CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	// Collision->SetSimulatePhysics(true);
	// Collision->SetEnableGravity(false);
	Collision->SetNotifyRigidBodyCollision(true);
	Collision->BodyInstance.SetCollisionProfileName("NoCollision");
	Collision->OnComponentHit.AddDynamic(this,&AObstacle::OnCompHit);
	Collision->SetupAttachment(RootComponent);
	 
	// Collision->OnComponentBeginOverlap.AddDynamic(this,&AObstacle::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	// Collision->SetRelativeScale3D(FVector(1.83f,1.55f,1.52f));
	// mesh->SetRelativeScale3D(FVector(0.25f,2.f,1.f));	
	SetActorScale3D(FVector(0.1f,0.02f,1.f));
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	//DrawDebugSphere(GetWorld(),GetActorLocation(),SphereRadius,20,FColor::Purple,false, -1,0,1);
}

// void AObstacle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyindex, bool bFromSweep,const FHitResult& SweepResult) {
// 	if(OtherActor!=nullptr && OtherActor!=this && OtherComp!=nullptr) {
// 		Destroy();
// 	}
// }

void AObstacle::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit) {
	if(OtherActor!=NULL && OtherActor!=this && OtherComp!=NULL) {
		UE_LOG(LogTemp,Warning,TEXT("Hit on %s"),*OtherActor->GetName());
	}
}


