#include <windows.h>
#include <string>
#include "output_debug_stream.h"
#include "game_menu.h"
#include "on_event.h"
#include "game_screen.h"
#include "hook_functions_direct.h"

int nCheckMenuCount = 0;

int prevMenuCount = 0;

extern ゲーム画面ステータス lastゲーム画面ステータス;

BOOL Hook_SetMenuCustom(HWND hWnd, HMENU hMenu) {
	if (hMenu == NULL) {
		return FALSE;
	}

	int count = GetMenuItemCount(hMenu);

	if (count >= 8) {
		// 「ユニット」のメニューアイテムを全角に変更
		changeMenuItemString(hMenu, 226, "ユニット(&U)"); // 226はリソースエディタでわかる「ユニット」のメニューID

	}

	// 「ファイル」のPOPUPを全角に変更
	changePopupString(hMenu, 0, "ファイル(&F)");

	int menu_count = GetMenuItemCount(hMenu);

	// メニューのインスタンスが変更されている
	if (hMenu != hNB7MenuCheckChange) {
		hNB7MenuCheckChange = hMenu;

		// OutputDebugStream(std::to_string(count).c_str());
		// OutputDebugStream("個メニューが設定されます\r\n");
		// OutputDebugStream("メニューが変わりました\r\n");

		// OpeningMovie時のメニューは2個
		if (menu_count == 2) {
			changePopupString(hMenu, 1, "ムービー中止(&M)");
			if (nCheckMenuCount != menu_count) {
				nCheckMenuCount = menu_count;
				onOpeningMovie();
			}
		}

		// ゲームが出来る状態になると、メニューが9個になる。一応8個以上で判定。
		if (menu_count == 9) {
			// メニューを追加した
			addMenuItem(GetMenu(hWnd), "メモリエディタ起動(&M)", RESOURCE_MENU_ID_BUSHOUEDIT, ADDITIONAL_MENU_ID_MEMORYEDITOR);
			addMenuItem(GetMenu(hWnd), "---", RESOURCE_MENU_ID_BUSHOUEDIT, NULL);

			OutputDebugStream("メニューを追加した\n");
		}
	}

	if (prevMenuCount != menu_count) {

		if (menu_count == 3) {
			if (prevMenuCount == 9) {
				onCastleBattlePreStart();
			}
			OutputDebugStream("籠城戦スクリーン中である\n");
		}

		if (menu_count == 4) {
			if (prevMenuCount == 9) {
				onYasenBattlePreStart();
			}
			OutputDebugStream("戦闘スクリーン中である\n");
		}

		if (menu_count == 9) {


			if (prevMenuCount == 4) {
				onYasenBattleEnd();
			}
			if (prevMenuCount == 3) {
				onCastleBattleEnd();
			}
			OutputDebugStream("戦術スクリーン中である\n");
		}

		prevMenuCount = menu_count;

	}

	return true;
}
