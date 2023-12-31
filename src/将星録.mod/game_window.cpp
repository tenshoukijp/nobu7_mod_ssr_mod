#include <windows.h>
#include "game_menu.h"
#include "game_font.h"
#include "output_debug_stream.h"
#include "load_form_mod.h"

HWND hNB7Wnd = NULL;

HWND* referenceOfNB7Wnd = NULL;

void onCreateWindow(HWND hWnd) {

	// ウィンドウハンドルを保存
	hNB7Wnd = hWnd;

	// 呼び出し元(WinMM.dll)に、「今回の起動ではちゃんとウィンドウが生成されたよ」と伝える。よってゲーム本体が起動された。
	*referenceOfNB7Wnd = hWnd;

	OutputDebugStream("ウィンドウ生成\n");

	// メニューがころころ変わるので、メニューの変更を検知するため。最初にこれを代入。主にHook_SetMenuで、使われている。
	hNB7MenuCheckChange = GetMenu(hNB7Wnd);

	// changePopupString(GetMenu(hNB7Wnd), 0, "ファイル(&F)");

	// メニューを追加した
	addMenuItem(GetSystemMenu(hNB7Wnd, FALSE), "メモ帳起動(&M)", RESOURCE_MENU_ID_EXIT, ADDITIONAL_MENU_ID_NOTEPAD);

	OutputDebugStream("メニューを追加した\n");

	OutputDebugStream("将星録の開始\n");

}

BOOL doneDestroyWindow = FALSE;
void onDestroyWindow() {
	if (!doneDestroyWindow) {
		OutputDebugStream("ウィンドウ破棄\r\n");
		Close_FormMod();
	}

	doneDestroyWindow = TRUE;
}
