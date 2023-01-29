// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "AbilitySystem/Attributes/LyraAttributeSet.h"
#include "Character/LyraCharacter.h"
#include "Character/LyraCharacter.h"

#include "TopDownMultiPartCharacter.generated.h"


/**
 * ALyraCharacter
 *
 *	The base character pawn class used by this project.
 *	Responsible for sending events to pawn components.
 *	New behavior should be added via pawn components when possible.
 */
UCLASS()
class ATopDownMultiPartCharacter : public ALyraCharacter
{
	GENERATED_UCLASS_BODY()
	
// Name of the Sprite component
static FName SpriteComponentName;

protected:
	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<UPaperFlipbookComponent*> FlipbookList;

	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<UPaperZDAnimationComponent*> AnimationComponentList;

	// The ability system component sub-object used by player characters.
	UPROPERTY(VisibleAnywhere, Category = "T4C|Ability")
	ULyraAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category="AttributeTest")
	TArray<FAttributeDefaults>	DefaultStartingData;
public:

	virtual void PostInitializeComponents() override;
	
	UPaperFlipbookComponent* CreateAndInitializeFlipbook(FName PartName);

	/** Returns Sprite subobject **/
	FORCEINLINE TArray<UPaperFlipbookComponent*> GetSprites() const { return FlipbookList; }

	/* Get the AnimInstance for use in sequencer, should create it if it doesn't exist. */
	UFUNCTION(BlueprintCallable, Category="Ability")
	void InitialiseAttributes() ;
	const UAttributeSet* GetOrCreateAttributeSubobject(TSubclassOf<UAttributeSet> AttributeClass);
	const UAttributeSet* GetAttributeSubobject(TSubclassOf<UAttributeSet> AttributeClass);
	virtual void OnAbilitySystemInitialized() override;
};

