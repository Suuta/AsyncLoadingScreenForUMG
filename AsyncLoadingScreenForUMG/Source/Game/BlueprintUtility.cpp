
#include "BlueprintUtility.h"
#include "LoadingScreen.h"


void UBlueprintUtility::StartLoadingScreen_Slate(bool bPlayUntilStopped)
{
    ILoadingScreenModule& LoadingScreenModule = ILoadingScreenModule::Get();
    LoadingScreenModule.StartInGameLoadingScreen(bPlayUntilStopped, -1);
}

void UBlueprintUtility::StopLoadingScreen_Slate()
{
    ILoadingScreenModule& LoadingScreenModule = ILoadingScreenModule::Get();
    LoadingScreenModule.StopInGameLoadingScreen();
}

