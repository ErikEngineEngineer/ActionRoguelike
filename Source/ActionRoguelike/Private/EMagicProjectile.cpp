// Fill out your copyright notice in the Description page of Project Settings.


#include "EMagicProjectile.h"
#include "Particles\ParticleSystemComponent.h"
#include "Components\SphereComponent.h"
#include "GameFramework\ProjectileMovementComponent.h"



// Sets default values
AEMagicProjectile::AEMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComp;
	SphereComp->SetCollisionProfileName("Projectile");


	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>("Particles");
	ParticleComp->SetupAttachment(SphereComp);

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileComponent");
	ProjectileComp->InitialSpeed = 1000.0f;
	ProjectileComp->bRotationFollowsVelocity = true;
	ProjectileComp->bInitialVelocityInLocalSpace = true;
	ProjectileComp->ProjectileGravityScale = 0.0f;
	

}

// Called when the game starts or when spawned
void AEMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

