

// このファイルは微妙に外れている？ でも重要な情報があるようにも思える
#include <windows.h>
#include <string>
#include "data_game_struct.h"
#include "data_bushou_struct.h"
#include "output_debug_stream.h"
#include "data_kahou_struct.h"
#include "data_kanni_struct.h"
#include "data_yakusyoku_struct.h"
#include "data_castle_struct.h"
#include "data_turn_struct.h"
#include "game_screen.h"
#include "game_process.h"
#include "on_serihu_message.h"
#include "bushou_albedo.h"
#include "game_screen.h"
#include "message_albedo.h"


using namespace std;

#pragma unmanaged

/*
大名ターンの情報があるかもしれない場所
00569280  28 00 00 00 78 00 00 00 14 00 00 00 64 00 00 00  (...x......d...
00569290  00 00 00 00 00 00 00 00 A0 00 00 00 A0 00 00 00  ........�...�...
005692A0  [26 AB 56] 00 16 00 00 00 40 00 00 00 01 00 00 00  &ｫV....@......
005692B0  00 00 00 00 [26 AB 56] 00 58 27 CE 07 01 00 00 00  ....&ｫV.X'ﾎ...
005692C0  16 00 00 00 E8 6F D4 07 40 2E 00 00 7A A6 00 00  ...鑰ﾔ@...zｦ..
005692D0  B6 3F 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ｶ?..............
005692E0  8C 5B 00 00 DA 1D 00 00 00 00 00 00 00 00 00 00  啓..ﾚ..........

0057EA74  78 A1 CE 07 01 00 00 00 [26 AB 56] 00 B8 8E 53 00  x｡ﾎ...&ｫV.ｸ惨. アドレス0x57EA7C = ここの[ ] が大名ターンの大名アドレスへの直接のポインタ [B8 8E 53 00] だと、誰もターン来てない。
0057EA84  [26 AB 56] 00 B8 8E 53 00 B8 8E 53 00 B8 8E 53 00  &ｫV.ｸ惨.ｸ惨.ｸ惨.
0057EA94  B8 8E 53 00 B8 8E 53 00 B8 8E 53 00 B8 8E 53 00  ｸ惨.ｸ惨.ｸ惨.ｸ惨.
0057EAA4  05 00 00 00 05 00 00 00 00 00 00 00 FF FF 00 00  ..........��..
*/#pragma once

/*
この0x57EA7Cへと代入している箇所はただ１つ。
004C4F7A   8B15 F8915300    MOV EDX,DWORD PTR DS:[5391F8]            ; Nobunaga.00538EB8
004C4F80   8915 7CEA5700    MOV DWORD PTR DS:[57EA7C],EDX
004C4F86   837C24 1C 00     CMP DWORD PTR SS:[ESP+1C],0
004C4F8B   0F85 AB000000    JNZ Nobunaga.004C503C
004C4F91   33FF             XOR EDI,EDI
004C4F93   8D6B 08          LEA EBP,DWORD PTR DS:[EBX+8]
*/

/*
その上記を呼び出している関数はたった１つ
0045F58B   B9 F0BF5E00      MOV ECX,Nobunaga.005EBFF0
0045F590   E8 5B590600      CALL Nobunaga.004C4EF0
0045F595   8B4C24 14        MOV ECX,DWORD PTR SS:[ESP+14]
0045F599   8D8424 44450000  LEA EAX,DWORD PTR SS:[ESP+4544]
0045F5A0   50               PUSH EAX
*/



void OnSSRExeDaimyoTurnExecute() {
	OutputDebugStream("大名ターン来たよ前★\n");
}

/*
この0x57EA7Cへと代入している箇所はただ１つ。
004C4F7A   8B15 F8915300    MOV EDX,DWORD PTR DS:[5391F8]            ; Nobunaga.00538EB8
004C4F80   8915 7CEA5700    MOV DWORD PTR DS:[57EA7C],EDX <--- ここをジャンプへと書き換える
004C4F86   837C24 1C 00     CMP DWORD PTR SS:[ESP+1C],0
004C4F8B   0F85 AB000000    JNZ Nobunaga.004C503C
004C4F91   33FF             XOR EDI,EDI
004C4F93   8D6B 08          LEA EBP,DWORD PTR DS:[EBX+8]
*/



int pSSRExeJumpFromToOnSSRExeDaimyoTurn = 0x4C4F80; // 関数はこのアドレスから、OnSSRExeDaimyoTurnへとジャンプしてくる。
// int pSSRExeJumpCallFromToOnSSRExeDaimyoTurn = 0x4C4EF0; // 元々あった処理のCall先
int pSSRExeReturnLblFromOnSSRExeDaimyoTurn = 0x4C4F86; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプする

#pragma warning(disable:4733)

__declspec(naked) void WINAPI OnSSRExeDaimyoTurn() {
	// スタックにためておく
	__asm {

		MOV DWORD PTR DS : [0x57EA7C] , EDX

		push eax
		push ebx
		push ecx
		push edx
		push esp
		push ebp
		push esi
		push edi
	}

	OnSSRExeDaimyoTurnExecute();

	__asm {
		pop edi
		pop esi
		pop ebp
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax

		jmp pSSRExeReturnLblFromOnSSRExeDaimyoTurn
	}
}
#pragma warning(default: 4733) // ワーニングの抑制を解除する



char cmdOnSSRExeJumpFromDaimyoTurn[6] = "\xE9";
// 元の命令が5バイト、以後の関数で生まれる命令が合計５バイトなので… 最後１つ使わない


// ニーモニック書き換え用
void WriteAsmJumperOnSSRExeDaimyoTurn() {

	// まずアドレスを数字として扱う
	int iAddress = (int)OnSSRExeDaimyoTurn;
	int SubAddress = iAddress - (pSSRExeJumpFromToOnSSRExeDaimyoTurn + 5);
	// ５というのは、0046C194  -E9 ????????  JMP TSMod.OnTSExeGetDaimyoKoukeishaBushouID  の命令に必要なバイト数。要するに５バイト足すと次のニーモニック命令群に移動するのだ。そしてそこからの差分がジャンプする際の目的格として利用される。
	memcpy(cmdOnSSRExeJumpFromDaimyoTurn + 1, &SubAddress, 4); // +1 はE9の次から4バイト分書き換えるから。

	// 構築したニーモニック命令をTENSHOU.EXEのメモリに書き換える
	WriteProcessMemory(hCurrentProcess, (LPVOID)(pSSRExeJumpFromToOnSSRExeDaimyoTurn), cmdOnSSRExeJumpFromDaimyoTurn, 5, NULL); //5バイトのみ書き込む
}

#pragma managed
