#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShakeBase.h"
#include "HordeTemplateCameraShakePattern.generated.h"

USTRUCT(BlueprintType)
struct FCameraShakeOscillator
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float Frequency;

	FCameraShakeOscillator()
		: Amplitude(0.f)
		, Frequency(0.f)
	{
	}
};

UCLASS()
class HORDETEMPLATEV2NATIVE_API UHordeTemplateCameraShakePattern : public UCameraShakePattern
{
	GENERATED_BODY()

public:
	UHordeTemplateCameraShakePattern(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float BlendInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float BlendOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float LocationAmplitudeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float LocationFrequencyMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float RotationAmplitudeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	float RotationFrequencyMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator Z;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator Pitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator Yaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator Roll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	FCameraShakeOscillator FOV;

protected:
	virtual void GetShakePatternInfoImpl(FCameraShakeInfo& OutInfo) const override;
	virtual void UpdateShakePatternImpl(const FCameraShakePatternUpdateParams& Params, FCameraShakePatternUpdateResult& OutResult) override;

private:
	float CurrentTime;
};
