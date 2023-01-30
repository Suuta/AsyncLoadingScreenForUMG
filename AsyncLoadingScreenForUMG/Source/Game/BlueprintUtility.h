
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintUtility.generated.h"


UCLASS()
class GAME_API UBlueprintUtility : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //-------------------------------------------------
    // Slate�p���[�h��� �X�^�[�g
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StartLoadingScreen_Slate(bool bPlayUntilStopped);

    //-------------------------------------------------
    // Slate�p���[�h��� �X�g�b�v
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StopLoadingScreen_Slate();

};
