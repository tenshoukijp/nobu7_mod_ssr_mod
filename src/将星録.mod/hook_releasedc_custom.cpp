#include <windows.h>
#include <string>
#include "output_debug_stream.h"
#include "on_event.h"
#include "hook_textouta_custom.h"
#include "on_serihu_message.h"
#include "bushou_albedo.h"
#include "data_game_struct.h"
#include "game_screen.h"
using namespace std;

extern string bufferTextOut;


extern int nCheckTextOutXStart;
extern int nCheckTextOutYStart;

int Hook_ReleaseDCCustom(
	HWND hWnd,  // ウィンドウのハンドル
	HDC hDC     // デバイスコンテキストのハンドル
) {

	nCheckTextOutXStart = -1;
	nCheckTextOutYStart = -1;

	if (bufferTextOut != "") {
		OutputDebugStream(bufferTextOut);
		OutputDebugStream("------------\n");
	}


	// アルベドの行動カウンタを減らす
	decreaseAlbedoKoudouCounter();

	dispatchEvent();
	bufferTextOut = "";

	return 1;
}
