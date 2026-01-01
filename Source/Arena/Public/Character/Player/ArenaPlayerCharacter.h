#pragma once

#include "CoreMinimal.h"
#include "Character/ArenaBaseCharacter.h"
#include "Component/StatComponent.h"
#include "ArenaPlayerCharacter.generated.h"

UCLASS()
class ARENA_API AArenaPlayerCharacter : public AArenaBaseCharacter
{
	GENERATED_BODY()

public:
	AArenaPlayerCharacter();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	UStatComponent* GetStatComponent() const { return StatComponent; }

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStatComponent> StatComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USceneComponent> WeaponTip;
};
