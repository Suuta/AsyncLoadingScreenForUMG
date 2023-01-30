
#pragma once

#include "Modules/ModuleManager.h"


class FAsyncLoadingScreenForUMGModule : public IModuleInterface
{
public:

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
