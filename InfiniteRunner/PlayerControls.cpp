// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControls.h"


// Sets default values
APlayerControls::APlayerControls()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh Rendering...
	mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshLoader(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	mesh->SetStaticMesh(MeshLoader.Object);
	material=CreateDefaultSubobject<UMaterial>(TEXT("Material"));
	ConstructorHelpers::FObjectFinder<UMaterial> MaterialLoader(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	mesh->SetMaterial(0,MaterialLoader.Object);

	// Camera Creation
	CameraSpring=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpring"));
	CameraSpring->SetupAttachment(RootComponent);
	CameraSpring->bEnableCameraLag=true;
	CameraSpring->CameraLagSpeed=1.5f;
	CameraSpring->bInheritPitch=false;
	CameraSpring->bInheritYaw=true;
	CameraSpring->bInheritRoll=false;
	CameraSpring->bUsePawnControlRotation=true;

	CameraSpring->SetRelativeLocation(FVector(0.f,0.f,0.f));

	Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraSpring,USpringArmComponent::SocketName);
	AutoPossessPlayer=EAutoReceiveInput::Player0;

	//Create Fire Particle
	Fire=CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	Fire->SetupAttachment(mesh);
	Fire->bAutoActivate=true;
	ConstructorHelpers::FObjectFinder<UParticleSystem> Particle(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if(Particle.Succeeded()) {
		Fire->SetTemplate(Particle.Object);
	}

	// Handling Collisions

}

// Called when the game starts or when spawned
void APlayerControls::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerControls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate Actor
	FRotator Rotation=FRotator(Pitch,Yaw,Roll);
	FQuat Quat=FQuat(Rotation);
	AddActorLocalRotation(Quat,false,0,ETeleportType::None);

	// Move Actor
	FVector Position=GetActorLocation();
	Position.X+=ForwardSpeed;
	SetActorRelativeLocation(Position);

	// Move Camera w.r.t Actor
	FVector CameraLocation=Camera->GetRelativeLocation();
	CameraLocation.X+=ForwardSpeed;
	Camera->SetRelativeLocation(CameraLocation);

	// Grounds Generation
	if((int)GetActorLocation().X / 2000 == GroundsCount) {
		UE_LOG(LogTemp,Warning,TEXT("Change!"));
		GroundsCount++;
		AGround* temp=Current;
		Current=Next;
		Next=temp;
		Next->SetActorLocation(FVector(NextXPos,0.f,50.f));
		NextXPos+=GroundSize;
	}
}

void APlayerControls::MoveHorizontal(float value) {
	if(value!=0.f) {
		FVector Location=GetActorLocation();
		Location.Y+=FMath::Clamp(value,-1.f,1.f)*HorizontalSpeed;
		SetActorRelativeLocation(Location);
	}
}

void APlayerControls::Jump() {
	UE_LOG(LogTemp,Warning,TEXT("Jump!"));
	mesh->AddForce(FVector(0.f,0.f,1.f)*10000*mesh->GetMass());
}

// Called to bind functionality to input
void APlayerControls::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Handle Inputs
	InputComponent->BindAxis("Horizontal",this,&APlayerControls::MoveHorizontal);
	//InputComponent->BindAction("Jump",IE_Pressed,this,&APlayerControls::Jump);
}

