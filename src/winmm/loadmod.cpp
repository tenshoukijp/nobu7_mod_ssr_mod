#include <windows.h>
#include "loadmod.h"

using PFNONINITIALIZE = void (WINAPI*)(void*);
using PFNONFINALIZE = void (WINAPI*)();

PFNONINITIALIZE pMod_onInitialize = NULL;
PFNONFINALIZE   pMod_onFinalize = NULL;

// «¯^Mod.dllÌÇÝÝ
HMODULE hNB7ModDll = NULL;
BOOL loadNB7Mod() {

	hNB7ModDll = LoadLibrary("«¯^.mod.dll");

	// ¶ÝµÈ¢
	if (!hNB7ModDll) {
		MessageBoxA(NULL, "«¯^Modª³¢", "G[", NULL);
		return FALSE;
	}

	return TRUE;
}

void freeNB7Mod() {
	if (hNB7ModDll) {
		FreeLibrary(hNB7ModDll);
		hNB7ModDll = NULL;
	}
}

HWND hNB7Wnd = NULL;
void Mod_onInitialize() {
	pMod_onInitialize = (PFNONINITIALIZE)GetProcAddress(hNB7ModDll, "onInitialize");
	if (hNB7ModDll && pMod_onInitialize) {
		pMod_onInitialize(&hNB7Wnd);
	}
}

