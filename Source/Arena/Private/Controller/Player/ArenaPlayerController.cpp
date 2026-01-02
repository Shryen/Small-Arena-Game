#include "Controller/Player/ArenaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/Player/ArenaPlayerCharacter.h"

void AArenaPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
			Subsystem->AddMappingContext(InputMappingContext, 0);
}

void AArenaPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AArenaPlayerController::Move);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AArenaPlayerController::Look);
		EnhancedInput->BindAction(FireAction, ETriggerEvent::Triggered, this, &AArenaPlayerController::Fire);
	}
}

void AArenaPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();
	if (APawn* ControlledPawn = Cast<APawn>(GetPawn()))
	{
		// Get Rotation
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get directions by rotation
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Apply Movement
		ControlledPawn->AddMovementInput(ForwardDirection, Input.Y); // Back and forth
		ControlledPawn->AddMovementInput(RightDirection, Input.X);	 // Right and Left
	}
}

void AArenaPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();
	AddPitchInput(-Input.Y);
	AddYawInput(Input.X);
}

void AArenaPlayerController::Fire(const FInputActionValue& Value)
{
	if (APawn* ControlledPawn = Cast<APawn>(GetPawn()))
		if (AArenaPlayerCharacter* ControlledCharacter = Cast<AArenaPlayerCharacter>(ControlledPawn))
			if (UObjectPoolManager* PoolManager = ControlledCharacter->GetObjectPoolManager())
			{
				FTransform Transform;
				Transform.SetLocation(ControlledCharacter->GetBulletSpawnLocation());
				Transform.SetRotation(GetControlRotation().Quaternion());
				PoolManager->SpawnFromPool(Transform);
			}
}

