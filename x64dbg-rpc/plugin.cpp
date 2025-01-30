#include "pch.h"
#include "plugin.h"

void doCallBack(CBTYPE cbType, void* callbackInfo)
{
    switch (cbType)
    {
    case CB_INITDEBUG:
        updateRPC(reinterpret_cast<PLUG_CB_INITDEBUG*>(callbackInfo));
        break;
    case CB_STOPDEBUG:
        resetRPC();
        break;
    }
}

bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registercallback(pluginHandle, CB_INITDEBUG, doCallBack);
    _plugin_registercallback(pluginHandle, CB_STOPDEBUG, doCallBack);
    return true;
}

void pluginSetup()
{
    initializeRPC();
    _plugin_logputs("[" PLUGIN_NAME "] Started RPC ");
}