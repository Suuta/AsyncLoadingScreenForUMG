
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/GameInstance.h"
#include "AsyncLoadingScreenForUMG_GI.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ASYNCLOADINGSCREENFORUMG_API UAsyncLoadingScreenForUMG_GI : public UGameInstance
{
    GENERATED_BODY()

public:

    //-------------------------------------------------
    // ���[�h��ʂɎg�p������UMG���w�肷��
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    void RegisterWidget(TSubclassOf<UUserWidget> Widget, bool bPlayOnPreLoadMapDelegate);

public:

    //-------------------------------------------------
    // static �Q�b�^�[
    //-------------------------------------------------
    static UAsyncLoadingScreenForUMG_GI* Get();

    //-------------------------------------------------
    // �����I�Ƀ��[�h��ʂ̊J�n�E��~���s��
    //-------------------------------------------------
    void StartLoadingScreen(bool bPlayUntilStopped);
    void StopLoadingScreen();

private:

    //-------------------------------------------------
    // FCoreUObjectDelegates����̃R�[���o�b�N�֐�
    //-------------------------------------------------
    void OnPreLoadMap(const FString& MapName);
    void OnPostLoadMap(UWorld* World);

private:

    UUserWidget*        UserWidget;  // UMG
    TSharedPtr<SWidget> SlateWidget; // Slate
};
