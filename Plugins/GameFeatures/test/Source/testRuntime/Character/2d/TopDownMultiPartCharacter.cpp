// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownMultiPartCharacter.h"

#include "AbilitySystem/LyraAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"

FName ATopDownMultiPartCharacter::SpriteComponentName(TEXT("Sprite0"));

ATopDownMultiPartCharacter::ATopDownMultiPartCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	
}

void ATopDownMultiPartCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (IsValid(this))
	{
		for (UPaperFlipbookComponent* FlipbookComponent : FlipbookList)
		{
			if (FlipbookComponent)
			{
				// force animation tick after movement component updates
				if (FlipbookComponent->PrimaryComponentTick.bCanEverTick && GetCharacterMovement())
				{
					FlipbookComponent->PrimaryComponentTick.AddPrerequisite(GetCharacterMovement(), GetCharacterMovement()->PrimaryComponentTick);
				}
			}
		}
	}
}

UPaperFlipbookComponent* ATopDownMultiPartCharacter::CreateAndInitializeFlipbook(FName PartName)
{
	UPaperFlipbookComponent* FlipbookComponent = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(PartName);
	if (FlipbookComponent)
	{
		FlipbookComponent->AlwaysLoadOnClient = true;
		FlipbookComponent->AlwaysLoadOnServer = true;
		FlipbookComponent->bOwnerNoSee = false;
		FlipbookComponent->bAffectDynamicIndirectLighting = true;
		FlipbookComponent->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		FlipbookComponent->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		FlipbookComponent->SetCollisionProfileName(CollisionProfileName);
		FlipbookComponent->SetGenerateOverlapEvents(false);
	}
	return FlipbookComponent;
}

void ATopDownMultiPartCharacter::InitialiseAttributes()
{
	UE_LOG(LogTemp, Warning, TEXT("InitialiseAttributes"));
	AbilitySystemComponent = GetLyraAbilitySystemComponent();
	// Init starting data
	for (int32 i=0; i < DefaultStartingData.Num(); ++i)
	{
		if (DefaultStartingData[i].Attributes && DefaultStartingData[i].DefaultStartingTable)
		{
			UAttributeSet* Attributes = const_cast<UAttributeSet*>(GetOrCreateAttributeSubobject(DefaultStartingData[i].Attributes));
			Attributes->InitFromMetaDataTable(DefaultStartingData[i].DefaultStartingTable);
		}
	}
}

const UAttributeSet* ATopDownMultiPartCharacter::GetOrCreateAttributeSubobject(TSubclassOf<UAttributeSet> AttributeClass)
{
	AActor* OwningActor = GetPlayerState();
	const UAttributeSet* MyAttributes = nullptr;
	if (OwningActor && AttributeClass)
	{
		MyAttributes = GetAttributeSubobject(AttributeClass);
		if (!MyAttributes)
		{
			UAttributeSet* Attributes = NewObject<UAttributeSet>(OwningActor, AttributeClass);
			AbilitySystemComponent->GetSpawnedAttributes_Mutable().AddUnique(Attributes);
			MyAttributes = Attributes;
			AbilitySystemComponent->bIsNetDirty = true;
		}
	}

	return MyAttributes;
}

const UAttributeSet* ATopDownMultiPartCharacter::GetAttributeSubobject(const TSubclassOf<UAttributeSet> AttributeClass)
{
	for (UAttributeSet* Set : AbilitySystemComponent->GetSpawnedAttributes())
	{
		if (Set && Set->IsA(AttributeClass))
		{
			return Set;
		}
	}
	return nullptr;
}

void ATopDownMultiPartCharacter::OnAbilitySystemInitialized() 
{
	
	Super::OnAbilitySystemInitialized();
	AbilitySystemComponent = GetLyraAbilitySystemComponent();
	InitialiseAttributes();
}