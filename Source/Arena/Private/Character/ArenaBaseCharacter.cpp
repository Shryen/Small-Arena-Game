#include "Character/ArenaBaseCharacter.h"

#include "Actor/ObjectPoolManager.h"


AArenaBaseCharacter::AArenaBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	ObjectPoolManager = CreateDefaultSubobject<UObjectPoolManager>(TEXT("BulletPoolManager"));
	
	BulletSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnLocation"));
	BulletSpawnLocation->SetupAttachment(GetRootComponent());
}

void AArenaBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArenaBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

