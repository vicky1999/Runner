// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

#include "Engine/TriggerBox.h"
#include "Obstacle.generated.h"

UCLASS()
class INFINITERUNNER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UPROPERTY(VisibleAnywhere,Category="Collision")
	// class USphereComponent* Collision;
	class UBoxComponent* Collision;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	UStaticMeshComponent* mesh;

	float SphereRadius;
	
	UFUNCTION()
	// void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyindex, bool bFromSweep,const FHitResult& SweepResult);
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
