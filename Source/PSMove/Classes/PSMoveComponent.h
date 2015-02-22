#pragma once

#include "IPSMove.h"
#include "PSMoveInterface.h"
#include "PSMoveComponent.generated.h"

UCLASS(ClassGroup="Input Controller", meta=(BlueprintSpawnableComponent))
class UPSMoveComponent : public UActorComponent//, public IPSMoveInterface
{
    GENERATED_UCLASS_BODY()

    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=PSMove)
    FVector Position;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=PSMove)
    FQuat Orientation;

    UFUNCTION(BlueprintImplementableEvent, meta=(FriendlyName = "PSMove Position and Orientation Updated"))
    void PositionAndOrientationUpdated(FVector SendPosition, FQuat SendOrientation);
};