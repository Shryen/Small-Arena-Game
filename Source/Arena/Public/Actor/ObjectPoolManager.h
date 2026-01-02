#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPoolManager.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ARENA_API UObjectPoolManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UObjectPoolManager();

protected:
	virtual void BeginPlay() override;
	
};
