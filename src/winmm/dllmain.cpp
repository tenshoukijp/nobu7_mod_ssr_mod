﻿#include <windows.h>
#include <string>
#include <wow64apiset.h>
#include "dllmain.h"
#include "process.h"
#include "dllextern.h"



BOOL isTargetExe = FALSE;
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {

        if (!IsWow64()) {
            MessageBox(NULL, "エラー", "「SysWow64」環境ではないようです。", NULL);
            return FALSE;
        }

        // C:\Windows\SysWow64のパスを取得。ほとんど全ての人はCドライブから変更していないとは思うが...
        char sysWow64Path[512] = "";
        UINT hasWow64Path = GetSystemWow64DirectoryA(sysWow64Path, sizeof(sysWow64Path));
        if (hasWow64Path == 0) {
            MessageBox(NULL, "エラー", "「SysWow64」のパスを取得できませんでした。", NULL);
            return FALSE;
        }
        strcat_s(sysWow64Path, "\\winmm.dll");

        h_original = LoadLibrary(sysWow64Path);
        if (h_original == NULL) {
            MessageBox(NULL, "エラー", "「SysWow64」内のwinmm.dllをロードできませんでした。", NULL);
            return FALSE;
        }

        // プロセスのフルパスに「Nobunaga7WPK.exe」が含まれているか？
        std::string fullPathName = GetCurrentProcessFullPath();
        MessageBoxA(NULL, fullPathName.c_str(), "フルパス", NULL);
        // 含まれているなら、将星録のexeが起動したということ。
        if (fullPathName.find("Nobunaga7WPK.exe") != std::string::npos) {
            // ここまで来たら「将星録本体」のexeが起動したということ。
            isTargetExe = TRUE;
            OutputDebugString("将星録の開始");
            setDllFuncAddress();
        }
        break;
    }
    case DLL_THREAD_ATTACH:
    {
        break;
    }
    case DLL_THREAD_DETACH:
    {
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        FreeLibrary(h_original);

        if (isTargetExe) {
            OutputDebugString("将星録の終了");
            isTargetExe = FALSE;
        }
        break;
    }
    default:
    {
        break;
    }

    } // switch

    return TRUE;
}

