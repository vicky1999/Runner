// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Ground.h"
#include "Particles/ParticleSystemComponent.h"
#include "PlayerControls.generated.h"

UCLASS()
class INFINITERUNNER_API APlayerControls : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerControls();

	UPROPERTY(EditAnywhere,blueprintReadWrite,Category="Mesh")
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mesh")
	UMaterial* material;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	USpringArmComponent* CameraSpring;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotate")
	float Pitch=0.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotate")
	float Yaw=0.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotate")
	float Roll=0.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	float ForwardSpeed=2.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	float HorizontalSpeed=2.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grounds")
	AGround* Current;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grounds")
	AGround* Next;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Fire")
	UParticleSystemComponent* Fire;

	int GroundsCount=1;
	float NextXPos=4800.f;
	float GroundSize=2000.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveHorizontal(float value);
	void Jump();
	
};
