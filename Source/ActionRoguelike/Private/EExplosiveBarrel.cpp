// Fill out your copyright notice in the Description page of Project Settings.


#include "EExplosiveBarrel.h"
#include "Components\StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AEExplosiveBarrel::AEExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = StaticMesh;
	StaticMesh->SetSimulatePhysics(true);
	StaticMesh->SetCollisionProfileName("PhysicsActor");
	//StaticMesh->SetNotifyRigidBodyCollision(true);//Generate Hit Event Checkmark in editor
	StaticMesh->OnComponentHit.AddDynamic(this, &AEExplosiveBarrel::OnComponentHit);

	RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForce->SetupAttachment(StaticMesh);
	RadialForce->Radius = 700.0f;
	RadialForce->bImpulseVelChange = true;
	RadialForce->bAutoActivate = false;
}

void AEExplosiveBarrel::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForce->FireImpulse();
}

// Called when the game starts or when spawned
void AEExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

