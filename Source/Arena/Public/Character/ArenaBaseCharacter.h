#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArenaBaseCharacter.generated.h"

UCLASS(Abstract)
class ARENA_API AArenaBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AArenaBaseCharacter();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;
	
};
