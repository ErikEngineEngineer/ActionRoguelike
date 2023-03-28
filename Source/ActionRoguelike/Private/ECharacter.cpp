// Fill out your copyright notice in the Description page of Project Settings.


#include "ECharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AECharacter::AECharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void AECharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AECharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value, false);
}

void AECharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value, false);
}

// Called every frame
void AECharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float DrawScale = 100.0f;
	const float Thickness = 5.0f;

	FVector LineStart = GetActorLocation();

	LineStart += GetActorRightVector() * 100.0f;

	FVector ActorDirection_LineEnd = LineStart + (GetActorForwardVector() * 100.0f);
	DrawDebugDirectionalArrow(GetWorld(), LineStart, ActorDirection_LineEnd, DrawScale, FColor::Yellow, false, 0.0f, 0, Thickness);

	FVector ControllerDirection_LineEnd = LineStart + (GetControlRotation().Vector() * 100.0f);
	DrawDebugDirectionalArrow(GetWorld(), LineStart, ControllerDirection_LineEnd, DrawScale, FColor::Green, false, 0.0f, 0, Thickness);

}

// Called to bind functionality to input
void AECharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AECharacter::MoveForward );
	PlayerInputComponent->BindAxis("MoveRight", this, &AECharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

