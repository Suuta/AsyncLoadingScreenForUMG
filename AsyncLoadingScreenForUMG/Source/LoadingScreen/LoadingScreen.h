#pragma once

#include "ModuleInterface.h"
#include "Modules/ModuleManager.h"


LOADINGSCREEN_API
class ILoadingScreenModule : public IModuleInterface
{
public:

    static inline ILoadingScreenModule& Get()
    {
        return FModuleManager::LoadModuleChecked<ILoadingScreenModule>("LoadingScreen");
    }

    virtual void StartInGameLoadingScreen(bool bPlayUntilStopped, float PlayTime) = 0;
    virtual void StopInGameLoadingScreen() = 0;

};