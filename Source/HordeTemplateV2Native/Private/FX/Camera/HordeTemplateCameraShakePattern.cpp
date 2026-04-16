#include "HordeTemplateCameraShakePattern.h"

UHordeTemplateCameraShakePattern::UHordeTemplateCameraShakePattern(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Duration(0.f)
	, BlendInTime(0.f)
	, BlendOutTime(0.f)
	, LocationAmplitudeMultiplier(1.f)
	, LocationFrequencyMultiplier(1.f)
	, RotationAmplitudeMultiplier(1.f)
	, RotationFrequencyMultiplier(1.f)
	, CurrentTime(0.f)
{
}

void UHordeTemplateCameraShakePattern::GetShakePatternInfoImpl(FCameraShakeInfo& OutInfo) const
{
	OutInfo.Duration = FCameraShakeDuration(Duration, ECameraShakeDurationType::Fixed);
	OutInfo.BlendIn = BlendInTime;
	OutInfo.BlendOut = BlendOutTime;
}

void UHordeTemplateCameraShakePattern::UpdateShakePatternImpl(const FCameraShakePatternUpdateParams& Params, FCameraShakePatternUpdateResult& OutResult)
{
	CurrentTime += Params.DeltaTime;

	const float TotalScale = Params.GetTotalScale();
	const float Time = CurrentTime;

	OutResult.Location.X = X.Amplitude * FMath::Sin(Time * X.Frequency * LocationFrequencyMultiplier) * LocationAmplitudeMultiplier * TotalScale;
	OutResult.Location.Y = Y.Amplitude * FMath::Sin(Time * Y.Frequency * LocationFrequencyMultiplier) * LocationAmplitudeMultiplier * TotalScale;
	OutResult.Location.Z = Z.Amplitude * FMath::Sin(Time * Z.Frequency * LocationFrequencyMultiplier) * LocationAmplitudeMultiplier * TotalScale;

	OutResult.Rotation.Pitch = Pitch.Amplitude * FMath::Sin(Time * Pitch.Frequency * RotationFrequencyMultiplier) * RotationAmplitudeMultiplier * TotalScale;
	OutResult.Rotation.Yaw = Yaw.Amplitude * FMath::Sin(Time * Yaw.Frequency * RotationFrequencyMultiplier) * RotationAmplitudeMultiplier * TotalScale;
	OutResult.Rotation.Roll = Roll.Amplitude * FMath::Sin(Time * Roll.Frequency * RotationFrequencyMultiplier) * RotationAmplitudeMultiplier * TotalScale;

	OutResult.FOV = FOV.Amplitude * FMath::Sin(Time * FOV.Frequency) * TotalScale;
}
