#include <windows.h>
#include <string>
#include "output_debug_stream.h"
#include "game_menu.h"
#include "on_event.h"
#include "game_screen.h"
#include "hook_functions_direct.h"
#include "mng_文字列変換.h"
#include "usr_custom_mod.h"
#include "mng_メニュー列挙.h"

/*
00419805   CALL DWORD PTR DS:[<&USER32.SetMenu>]                           将星録_m.77F8E307
0045CA45   CALL DWORD PTR DS:[<&USER32.EnableMenuItem>]                    将星録_m.77F8E361
0045CA70   CALL DWORD PTR DS:[<&USER32.EnableMenuItem>]                    将星録_m.77F8E361
0045DA5E   CALL DWORD PTR DS:[<&USER32.SetMenu>]                           将星録_m.77F8E307
0045DA87   CALL DWORD PTR DS:[<&USER32.SetMenu>]                           将星録_m.77F8E307
0045DAB1   CALL DWORD PTR DS:[<&USER32.SetMenu>]                           将星録_m.77F8E307
*/

/*
004197DA   . 52             PUSH EDX                                                   ; /hWnd => 00130EEA ('信長の野望･将星録 パワーアッ・..',class='信長の野望･将星録 パワーアッ・..')
004197DB   . FF15 90025200  CALL DWORD PTR DS:[<&USER32.GetMenu>]                      ; \GetMenu
004197E1   . 3BC5           CMP EAX,EBP
004197E3   . 74 07          JE SHORT Nobunaga.004197EC
004197E5   . 50             PUSH EAX                                                   ; /hMenu
004197E6   . FF15 94025200  CALL DWORD PTR DS:[<&USER32.DestroyMenu>]                  ; \DestroyMenu
004197EC   > A1 30B16000    MOV EAX,DWORD PTR DS:[60B130]
004197F1   . 68 82000000    PUSH 82                                                    ; /RsrcName = 82
004197F6   . 50             PUSH EAX                                                   ; |hInst => 00400000
004197F7   . FF15 98025200  CALL DWORD PTR DS:[<&USER32.LoadMenuA>]                    ; \LoadMenuA
004197FD   . 8B0D 34B16000  MOV ECX,DWORD PTR DS:[60B134]
00419803   . 50             PUSH EAX                                                   ; /hMenu
00419804   . 51             PUSH ECX                                                   ; |hWnd => 00130EEA ('信長の野望･将星録 パワーアッ・..',class='信長の野望･将星録 パワーアッ・..')
00419805   . FF15 F0025200  CALL DWORD PTR DS:[<&USER32.SetMenu>]                      ; \SetMenu
0041980B   . 8B9C24 2401000>MOV EBX,DWORD PTR SS:[ESP+124]
00419812   . 33FF           XOR EDI,EDI

*/
/*
0045DA40  |. 8B0D 30B16000  MOV ECX,DWORD PTR DS:[60B130]                              ;  Nobunaga.00400000
0045DA46  |. 68 D1070000    PUSH 7D1                                                   ; /RsrcName = 7D1
0045DA4B  |. 51             PUSH ECX                                                   ; |hInst => 00400000
0045DA4C  |. FF15 98025200  CALL DWORD PTR DS:[<&USER32.LoadMenuA>]                    ; \LoadMenuA
0045DA52  |. 8B15 34B16000  MOV EDX,DWORD PTR DS:[60B134]
0045DA58  |. 50             PUSH EAX                                                   ; /hMenu
0045DA59  |. 52             PUSH EDX                                                   ; |hWnd => 00130EEA ('信長の野望･将星録 パワーアッ・..',class='信長の野望･将星録 パワーアッ・..')
0045DA5A  |. 894424 18      MOV DWORD PTR SS:[ESP+18],EAX                              ; |
0045DA5E  |. FF15 F0025200  CALL DWORD PTR DS:[<&USER32.SetMenu>]                      ; \SetMenu
0045DA64  |. EB 56          JMP SHORT Nobunaga.0045DABC
0045DA66  |> A8 02          TEST AL,2
0045DA68  |. 74 2A          JE SHORT Nobunaga.0045DA94
0045DA6A  |. A1 30B16000    MOV EAX,DWORD PTR DS:[60B130]
0045DA6F  |. 68 D2070000    PUSH 7D2                                                   ; /RsrcName = 7D2
0045DA74  |. 50             PUSH EAX                                                   ; |hInst => 00400000
0045DA75  |. FF15 98025200  CALL DWORD PTR DS:[<&USER32.LoadMenuA>]                    ; \LoadMenuA
0045DA7B  |. 8B0D 34B16000  MOV ECX,DWORD PTR DS:[60B134]
0045DA81  |. 50             PUSH EAX                                                   ; /hMenu
0045DA82  |. 51             PUSH ECX                                                   ; |hWnd => 00130EEA ('信長の野望･将星録 パワーアッ・..',class='信長の野望･将星録 パワーアッ・..')
0045DA83  |. 894424 18      MOV DWORD PTR SS:[ESP+18],EAX                              ; |
0045DA87  |. FF15 F0025200  CALL DWORD PTR DS:[<&USER32.SetMenu>]                      ; \SetMenu
0045DA8D  |. BD 01000000    MOV EBP,1
0045DA92  |. EB 28          JMP SHORT Nobunaga.0045DABC
0045DA94  |> 8B15 30B16000  MOV EDX,DWORD PTR DS:[60B130]                              ;  Nobunaga.00400000
0045DA9A  |. 68 D3070000    PUSH 7D3                                                   ; /RsrcName = 7D3
0045DA9F  |. 52             PUSH EDX                                                   ; |hInst => 00400000
0045DAA0  |. FF15 98025200  CALL DWORD PTR DS:[<&USER32.LoadMenuA>]                    ; \LoadMenuA
0045DAA6  |. 50             PUSH EAX                                                   ; /hMenu
0045DAA7  |. 894424 14      MOV DWORD PTR SS:[ESP+14],EAX                              ; |
0045DAAB  |. A1 34B16000    MOV EAX,DWORD PTR DS:[60B134]                              ; |
0045DAB0  |. 50             PUSH EAX                                                   ; |hWnd => 00130EEA ('信長の野望･将星録 パワーアッ・..',class='信長の野望･将星録 パワーアッ・..')
0045DAB1  |. FF15 F0025200  CALL DWORD PTR DS:[<&USER32.SetMenu>]                      ; \SetMenu
0045DAB7  |. BD 02000000    MOV EBP,2
0045DABC  |> 8B1D 48025200  MOV EBX,DWORD PTR DS:[<&USER32.EnableMenuItem>]            ;  将星録_m.77F8E361

*/


void AddGameModMainScreenMenu(HWND hWnd) {
	HMENU hTarget = GetMenu(hWnd);
	// insertMenuItem(hTarget, "テストエディタ(&T)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_TEST_KAI);
	insertMenuItem(hTarget, "大名エディタ(&D)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_DAIMYOEDIT_KAI);
	insertMenuItem(hTarget, "城エディタ(&S)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_CASTLEEDIT_KAI);
	insertMenuItem(hTarget, "武将エディタ(&B)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_BUSYOUEDIT_KAI);
	insertMenuItem(hTarget, "ユニットエディタ(&U)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_UNITEDIT_KAI);
	insertMenuItem(hTarget, "家宝エディタ(&I)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_KAHOUEDIT_KAI);
	insertMenuItem(hTarget, "官位エディタ(&R)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_KANNIEDIT_KAI);
	insertMenuItem(hTarget, "役職エディタ(&Y)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_YAKUSYOKUEDIT_KAI);
	insertMenuItem(hTarget, "年月相場エディタ(&N)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_NENNGETSUEDIT_KAI);
	insertMenuItem(hTarget, "---", RESOURCE_MENU_ID_KAIZOU_END, NULL);

}

void AddGameModYanseMenu(HWND hWnd) {
	HMENU hTarget = GetMenu(hWnd);
	insertMenuItem(hTarget, "野戦エディタ(&Y)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_YASENEDIT_KAI);
	insertMenuItem(hTarget, "野戦攻撃部隊エディタ(&K)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_YASENATTACKBUTAI_EDIT_KAI);
	insertMenuItem(hTarget, "野戦防御部隊エディタ(&B)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_YASENDEFENDBUTAI_EDIT_KAI);
	insertMenuItem(hTarget, "---", RESOURCE_MENU_ID_KAIZOU_END, NULL);
}

void AddGameModRojounseMenu(HWND hWnd) {
	HMENU hTarget = GetMenu(hWnd);
	insertMenuItem(hTarget, "籠城戦攻撃部隊エディタ(&K)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_ROUJOSENATTACKBUTAI_EDIT_KAI);
	insertMenuItem(hTarget, "籠城戦防御部隊エディタ(&B)", RESOURCE_MENU_ID_KAIZOU_END, ADDITIONAL_MENU_ID_ROUJOSENDEFENDBUTAI_EDIT_KAI);
	insertMenuItem(hTarget, "---", RESOURCE_MENU_ID_KAIZOU_END, NULL);
}


int prevLoadMenuID = -1;
extern int lastLoadMenuID;

BOOL Hook_SetMenuCustom(HWND hWnd, HMENU hMenu) {
	if (hMenu == NULL) {
		return FALSE;
	}

	int menu_count = GetMenuItemCount(hMenu);

	menu_count = GetMenuItemCount(hMenu); // 一応変わらないはずだけど再度取得しておく。

	// メニューのインスタンスが変更されている
	if (hMenu != hNB7MenuCheckChange) {
		hNB7MenuCheckChange = hMenu;

		try {
			System::Collections::Generic::Dictionary<System::String^, System::Object^>^ dic = gcnew System::Collections::Generic::Dictionary<System::String^, System::Object^>(5);
			dic->Add("メニュー番号", lastLoadMenuID);
			auto ret = InvokeUserMethod("onメニュー追加要求時", dic);
		}
		catch (System::Exception^) {
			OutputDebugStream("onメニュー追加要求時 で例外が発生しました。\n");
		}


		// OutputDebugStream(std::to_string(count).c_str());
		// OutputDebugStream("個メニューが設定されます\r\n");
		// OutputDebugStream("メニューが変わりました\r\n");

		// OpeningMovie時のメニューは2個 + 改造メニューで+1
		if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::オープニングメニュー) {
			// changePopupString(hMenu, 1, "ムービー中止(&M)");
			onOpeningMovie();
		}

		// ゲームが出来る状態になると、メニューが9個になる。一応8個以上で判定。
		if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::戦略メニュー) {
			// メニューを追加した
			AddGameModMainScreenMenu(hWnd);
		}

		else if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::野戦メニュー) {
			// メニューを追加した
			AddGameModYanseMenu(hWnd);
		}

		else if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::籠城戦メニュー) {
			// メニューを追加した
			AddGameModRojounseMenu(hWnd);
		}

	}

	if (prevLoadMenuID != lastLoadMenuID) {


		if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::籠城戦メニュー) { 
			if (prevLoadMenuID == 将星録::列挙::アプリケーション::メニュー::戦略メニュー) {
				onCastleBattlePreStart();
				OutputDebugStream("メニュー切り替わり(戦略⇒籠城戦)\n");
			}

			OutputDebugStream("籠城戦スクリーン中である\n");
		}

		else if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::野戦メニュー) {
			if (prevLoadMenuID == 将星録::列挙::アプリケーション::メニュー::戦略メニュー) {
				OutputDebugStream("メニュー切り替わり(戦略⇒野戦)\n");
				onYasenBattlePreStart();
			}

			OutputDebugStream("野戦スクリーン中である\n");
		}

		else if (lastLoadMenuID == 将星録::列挙::アプリケーション::メニュー::戦略メニュー) { 


			if (prevLoadMenuID == 将星録::列挙::アプリケーション::メニュー::野戦メニュー) { 
				OutputDebugStream("メニュー切り替わり(野戦⇒戦略)\n");
				onYasenBattleEnd();
			}
			else if (prevLoadMenuID == 将星録::列挙::アプリケーション::メニュー::籠城戦メニュー) {
				OutputDebugStream("メニュー切り替わり(籠城戦⇒戦略)\n");
				onCastleBattleEnd();
			}

		}

		prevLoadMenuID = lastLoadMenuID;

	}

	return true;
}
