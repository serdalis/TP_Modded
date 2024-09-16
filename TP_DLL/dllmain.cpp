// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <fstream>  

typedef struct Weapons {
    void* light;
    void** lightWeapon;
    void** lightWeapons;
    void* medium;
    void** mediumWeapon;
    void** mediumWeapons;
    void* heavy;
    void** heavyWeapon;
    void** heavyWeapons;

} Weapons;

// Lets put the internal functions here
typedef void __fastcall InitWeaponAllowedList(Weapons* Weapons);
InitWeaponAllowedList* initWeapons = (InitWeaponAllowedList*)0x00519340;

typedef LPSTR* AddString(void* str, LPSTR* list);
AddString* addString = (AddString*)0x004078b0;

typedef void AddObject(void* param_1, int param_2, void* param_3, void* param_4, unsigned int param_5, char param_6);
AddObject* addObject = (AddObject*)0x0041c7c0;

#define DLL_EXPORT extern "C" __declspec(dllexport)



namespace TP_Extender
{
    static HMODULE Exe_Handle = NULL;

    DLL_EXPORT void __fastcall initWeaponsDll(Weapons* weapons)
    {
        initWeapons(weapons);
    }

    void ProcessAttach(HMODULE myHandle)
    {
    }

    DLL_EXPORT bool __stdcall DllMain(HMODULE hModule,
        DWORD  ul_reason_for_call,
        LPVOID lpReserved)
    {
        Exe_Handle = GetModuleHandle(NULL);

        switch (ul_reason_for_call)
        {
            case DLL_PROCESS_ATTACH:
                ProcessAttach(hModule);
            break;
        }

        return true;
    }
}