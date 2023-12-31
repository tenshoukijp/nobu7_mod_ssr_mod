#pragma once

#include <windows.h>

#define ターン大名情報アドレス 0x57EA7C

#pragma pack(1)
struct NB7ターン大名情報型 {
	int* pターン大名; // 現在ターンが回っている大名のポインタ [B8 8E 53 00] だと、誰もターン来てない。
};
#pragma pack()

// ターンが来てる大名情報のID
int getStrategyTurnDaimyoID();

// ターンが来てる大名家の(大名の)武将ID
int getStrategyTurnDaimyoBushouID();

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
* この0x57EA7Cへと代入している箇所はただ１つ。
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