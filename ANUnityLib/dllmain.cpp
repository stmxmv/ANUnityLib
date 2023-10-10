// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "IUnityInterface.h"
#include "IUnityLog.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

IUnityLog* UnityLog;

extern "C" 	__declspec(dllexport)
void InitDarkModeRoutineOnce(BOOL useDark, BOOL fixDarkScrollbar);

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
UnityPluginLoad(IUnityInterfaces * unityInterfaces)
{
    UnityLog = unityInterfaces->Get<IUnityLog>();

    //UNITY_LOG(UnityLog, "ANUnityLib Loaded");
}

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
UnityPluginUnload()
{
    //UNITY_LOG(UnityLog, "ANUnityLib Unloaded");
}


