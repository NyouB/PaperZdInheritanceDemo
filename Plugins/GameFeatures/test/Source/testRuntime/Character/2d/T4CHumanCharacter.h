// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDAnimationComponent.h"
#include "TopDownMultiPartCharacter.h"
#include "Character/LyraCharacter.h"

#include "T4CHumanCharacter.generated.h"

/**
 * ALyraCharacter
 *
 *	The base character pawn class used by this project.
 *	Responsible for sending events to pawn components.
 *	New behavior should be added via pawn components when possible.
 */
UCLASS()
class AT4CHumanCharacter : public ATopDownMultiPartCharacter, public IPaperZDSequencerSource
{
	GENERATED_UCLASS_BODY()
	
// Name of the Sprite component
	static FName HairSpriteComponentName;
	static FName HeadSpriteComponentName;
	static FName BodySpriteComponentName;
	static FName LeftArmSpriteComponentName;
	static FName LeftHandSpriteComponentName;
	static FName RightArmSpriteComponentName;
	static FName RightHandSpriteComponentName;
	static FName LegSpriteComponentName;
	static FName FeetSpriteComponentName;
	static FName Feet2SpriteComponentName;
	static FName NakedSpriteComponentName;
	
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* HairSpriteBook;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* HeadSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* BodySpriteBook;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* LeftArmSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* LeftHandSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* RightArmSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* RightHandSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* LegSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* FeetSpriteBook ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperFlipbookComponent* NakedSpriteBook;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* Hair;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* Head ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* Body;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* LeftArm ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* LeftHand ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* RightArm ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* RightHand ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* Leg ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* Feet ;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaperZDAnimationComponent* Naked ;

public:
	//getters
	FORCEINLINE UPaperZDAnimationComponent* GetNaked() const { return Naked; }

	/* Obtain the AnimInstance class that is used for driving the animations. */
	virtual TSubclassOf<UPaperZDAnimInstance> GetSequencerAnimInstanceClass() const override;

	/* Get the AnimInstance for use in sequencer, should create it if it doesn't exist. */
	virtual UPaperZDAnimInstance* GetSequencerAnimInstance() override;
};

