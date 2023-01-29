// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/LyraCameraMode.h"
#include "Curves/CurveFloat.h"
#include "GameFramework/SpringArmComponent.h"

#include "T4CCameraMode_TopDownRPGCamera.generated.h"


class UCurveVector;


/**
 * ULyraCameraMode_TopDownRPGCamera
 *
 *	A basic third person camera mode that looks down to the player and keep it in the view center.
 */
UCLASS(Blueprintable)
class UT4CCameraMode_TopDownRPGCamera: public ULyraCameraMode
{
	GENERATED_BODY()


protected:

	//~ULyraCameraMode interface
	virtual void UpdateView(float DeltaTime) override;
	void Opposite(float x, float y, float z);

	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
	FRotator DefaultPivotRotation;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
	float DistanceTransform;
};
