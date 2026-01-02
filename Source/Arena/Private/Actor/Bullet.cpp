#include "Actor/Bullet.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = false;
	BulletCollision = CreateDefaultSubobject<USphereComponent>(TEXT("BulletCollision"));
	BulletCollision->SetupAttachment(GetRootComponent());
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABullet::SetInUse(bool bInUse)
{
	Super::SetInUse(bInUse);
	
	if (bInUse)
		ProjectileMovementComponent->Velocity = GetActorForwardVector() * 700.f;
	else
		ProjectileMovementComponent->Velocity = FVector::ZeroVector;
}



