#include "Character/ArenaBaseCharacter.h"


AArenaBaseCharacter::AArenaBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AArenaBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArenaBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

