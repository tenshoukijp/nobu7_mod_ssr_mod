#include <windows.h>
#include "loadmod.h"

using PFNONINITIALIZE = void (WINAPI*)(void*);
extern PFNONINITIALIZE pMod_onInitialize;

using PFNONGAMEINITIALIZE = void (WINAPI*)(HWND);
extern PFNONGAMEINITIALIZE pMod_onGameInitialize;

using PFNONFINALIZE = void (WINAPI*)();
extern PFNONFINALIZE pMod_onFinalize;

PFNONINITIALIZE pMod_onInitialize = NULL;
PFNONGAMEINITIALIZE pMod_onGameInitialize = NULL;
PFNONFINALIZE   pMod_onFinalize = NULL;

// «―^Mod.dllΜΗέέ
HMODULE hNB7ModDll = NULL;
BOOL loadNB7Mod() {

	hNB7ModDll = LoadLibrary("«―^.mod.dll");

	// Άέ΅Θ’
	if (!hNB7ModDll) {
		MessageBoxA(NULL, "«―^Modͺ³’", "G[", NULL);
		return FALSE;
	}

	return TRUE;
}

void freeNB7Mod() {
	if (hNB7ModDll) {

		Mod_onFinalize();

		FreeLibrary(hNB7ModDll);
		hNB7ModDll = NULL;
	}
}


void Mod_onInitialize() {
	pMod_onInitialize = (PFNONINITIALIZE)GetProcAddress(hNB7ModDll, "onInitialize");
	if (hNB7ModDll && pMod_onInitialize) {
		pMod_onInitialize(NULL);
	}
}

void Mod_onGameInitialize(HWND hWnd) {
	pMod_onGameInitialize = (PFNONGAMEINITIALIZE)GetProcAddress(hNB7ModDll, "onGameInitialize");
	if (hNB7ModDll && pMod_onGameInitialize) {
		pMod_onGameInitialize(hWnd);
	}
}

void Mod_onFinalize() {
	pMod_onFinalize = (PFNONFINALIZE)GetProcAddress(hNB7ModDll, "onFinalize");
	if (hNB7ModDll && pMod_onFinalize) {
		OutputDebugString("onFinalizeπΔΡo·ζ\n");
		pMod_onFinalize();
	}
}