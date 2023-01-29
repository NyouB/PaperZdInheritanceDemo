// Copyright Epic Games, Inc. All Rights Reserved.

#include "T4CHumanCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

FName AT4CHumanCharacter::HairSpriteComponentName(TEXT("HairSprite"));
FName AT4CHumanCharacter::HeadSpriteComponentName(TEXT("HeadSprite"));
FName AT4CHumanCharacter::BodySpriteComponentName(TEXT("BodySprite"));
FName AT4CHumanCharacter::LeftArmSpriteComponentName(TEXT("LeftArmSprite"));
FName AT4CHumanCharacter::LeftHandSpriteComponentName(TEXT("LeftHandSprite"));
FName AT4CHumanCharacter::RightArmSpriteComponentName(TEXT("RightArmSprite"));
FName AT4CHumanCharacter::RightHandSpriteComponentName(TEXT("RightHandSprite"));
FName AT4CHumanCharacter::LegSpriteComponentName(TEXT("LegSprite"));
FName AT4CHumanCharacter::FeetSpriteComponentName(TEXT("FeetSprite"));
FName AT4CHumanCharacter::Feet2SpriteComponentName(TEXT("Feet2Sprite"));
FName AT4CHumanCharacter::NakedSpriteComponentName(TEXT("NakedSprite"));

AT4CHumanCharacter::AT4CHumanCharacter(const FObjectInitializer& ObjectInitializer)
{
	HairSpriteBook= CreateAndInitializeFlipbook(HairSpriteComponentName);
	HeadSpriteBook=CreateAndInitializeFlipbook(HeadSpriteComponentName);
	BodySpriteBook=CreateAndInitializeFlipbook(BodySpriteComponentName);
	LeftArmSpriteBook=CreateAndInitializeFlipbook(LeftArmSpriteComponentName);
	LeftHandSpriteBook=CreateAndInitializeFlipbook(LeftHandSpriteComponentName);
	RightArmSpriteBook=CreateAndInitializeFlipbook(RightArmSpriteComponentName);
	RightHandSpriteBook=CreateAndInitializeFlipbook(RightHandSpriteComponentName);
	LegSpriteBook=CreateAndInitializeFlipbook(LegSpriteComponentName);
	FeetSpriteBook = CreateAndInitializeFlipbook(FeetSpriteComponentName);
	NakedSpriteBook=CreateAndInitializeFlipbook(NakedSpriteComponentName);

	Hair = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Hair"));
	Hair->InitRenderComponent(HairSpriteBook);
	Head = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Head"));
	Head->InitRenderComponent(HeadSpriteBook);
	Body = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Body"));
	Body->InitRenderComponent(BodySpriteBook);
	LeftArm = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("LeftArm"));
	LeftArm->InitRenderComponent(LeftArmSpriteBook);
	LeftHand = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("LeftHand"));
	LeftHand->InitRenderComponent(LeftHandSpriteBook);
	RightArm = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("RightArm"));
	RightArm->InitRenderComponent(RightArmSpriteBook);
	RightHand = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("RightHand"));
	RightHand->InitRenderComponent(RightHandSpriteBook);
	Leg = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Leg"));
	Leg->InitRenderComponent(LegSpriteBook);
	Feet = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Feet"));
	Feet->InitRenderComponent(FeetSpriteBook);
	Naked = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Naked"));
	Naked->InitRenderComponent(NakedSpriteBook);

	FlipbookList.Add(HairSpriteBook);
	FlipbookList.Add(HeadSpriteBook);
	FlipbookList.Add(BodySpriteBook);
	FlipbookList.Add(LeftArmSpriteBook);
	FlipbookList.Add(LeftHandSpriteBook);
	FlipbookList.Add(RightArmSpriteBook);
	FlipbookList.Add(RightHandSpriteBook);
	FlipbookList.Add(LegSpriteBook);
	FlipbookList.Add(FeetSpriteBook);
	FlipbookList.Add(NakedSpriteBook);
}

TSubclassOf<UPaperZDAnimInstance> AT4CHumanCharacter::GetSequencerAnimInstanceClass() const
{
	return Naked->GetSequencerAnimInstanceClass();
}

UPaperZDAnimInstance* AT4CHumanCharacter::GetSequencerAnimInstance()
{
	return Naked->GetSequencerAnimInstance();
}

