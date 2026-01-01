#pragma once

#include "CoreMinimal.h"
#include "Character/ArenaBaseCharacter.h"
#include "ArenaPlayerCharacter.generated.h"

UCLASS()
class ARENA_API AArenaPlayerCharacter : public AArenaBaseCharacter
{
	GENERATED_BODY()

public:
	AArenaPlayerCharacter();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;
};
