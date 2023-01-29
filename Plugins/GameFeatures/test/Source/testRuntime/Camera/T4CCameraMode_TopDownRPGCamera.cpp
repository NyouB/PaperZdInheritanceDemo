// Copyright Epic Games, Inc. All Rights Reserved.

#include "T4CCameraMode_TopDownRPGCamera.h"

#include <string>

#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "ThirdParty/Imath/Deploy/Imath-3.1.3/include/Imath/ImathMath.h"


void UT4CCameraMode_TopDownRPGCamera::UpdateView(float DeltaTime)
{
	const AActor* TargetActor = GetTargetActor();
	check(TargetActor);
	FVector TargetLocation = TargetActor->GetActorLocation();
	bool DistanceIsNegative = DistanceTransform < 0;
	float AbsoluteDistance = FMath::Abs(DistanceTransform);

	float opposite = UKismetMathLibrary::Cos(FMath::DegreesToRadians(DefaultPivotRotation.Pitch)) * AbsoluteDistance;

	float x = UKismetMathLibrary::Sin(FMath::DegreesToRadians(DefaultPivotRotation.Pitch)) * AbsoluteDistance;
	float y = UKismetMathLibrary::Sin(FMath::DegreesToRadians(DefaultPivotRotation.Yaw)) * opposite;
	float z = UKismetMathLibrary::Cos(FMath::DegreesToRadians(DefaultPivotRotation.Yaw)) * opposite;

	// if (DistanceIsNegative)
	// {
	// 	Opposite(x, y, z);
	// }
	FVector CameraFinalLocation = TargetLocation.operator+(FVector(x, y, z));
	// UE_LOG(LogUnrealMath, Log, TEXT("opposite: %f x: %f y: %f z: %f final: x %f y %f z %f"), opposite, x, y, z, intermediate.X, intermediate.Y, intermediate.Z);
	View.Location = CameraFinalLocation;
	View.Rotation = UKismetMathLibrary::FindLookAtRotation(CameraFinalLocation, TargetLocation);
	View.ControlRotation = View.Rotation;
	View.FieldOfView = FieldOfView;
}
void UT4CCameraMode_TopDownRPGCamera::Opposite(float x, float y, float z)
{
	x = -x;
	y = -y;
	z = -z;
}
