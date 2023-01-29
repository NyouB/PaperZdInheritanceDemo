// Copyright Epic Games, Inc. All Rights Reserved.

#include "OtherPaperCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// #include "PaperFlipbookComponent.h"

FName AOtherPaperCharacter::SpriteComponentName(TEXT("Sprite0"));

//////////////////////////////////////////////////////////////////////////
// APaperCharacter

AOtherPaperCharacter::AOtherPaperCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	// // Try to create the sprite component
	// Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(AOtherPaperCharacter::SpriteComponentName);
	// if (Sprite)
	// {
	// 	Sprite->AlwaysLoadOnClient = true;
	// 	Sprite->AlwaysLoadOnServer = true;
	// 	Sprite->bOwnerNoSee = false;
	// 	Sprite->bAffectDynamicIndirectLighting = true;
	// 	Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	// 	Sprite->SetupAttachment(GetCapsuleComponent());
	// 	static FName CollisionProfileName(TEXT("CharacterMesh"));
	// 	Sprite->SetCollisionProfileName(CollisionProfileName);
	// 	Sprite->SetGenerateOverlapEvents(false);
	// }
}

void AOtherPaperCharacter::PostInitializeComponents()
{
	// Super::PostInitializeComponents();
	//
	// if (IsValid(this))
	// {
	// 	if (Sprite)
	// 	{
	// 		// force animation tick after movement component updates
	// 		if (Sprite->PrimaryComponentTick.bCanEverTick && GetCharacterMovement())
	// 		{
	// 			Sprite->PrimaryComponentTick.AddPrerequisite(GetCharacterMovement(), GetCharacterMovement()->PrimaryComponentTick);
	// 		}
	// 	}
	// }
}
