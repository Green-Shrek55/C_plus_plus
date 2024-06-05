// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <string>
using namespace std;

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

extern "C" __declspec(dllexport) bool containsAllSymbols(const char* str, const char* chars) {
    string s(str);
    string c(chars);

    for (char ch : c) {
        if (s.find(ch) == string::npos) {
            return false;
        }
    }
    return true;
}