#pragma once


#include <windows.h>
#include "mng_武将列挙.h"

#define 大名情報アドレス 0x569848


#define 大名武将なし 0x5694b0


#define 援軍要請大名なし 0x538eb8


#define 敵対大名なし 0x538eb8


#define 大名居城なし 0x539000


// 322バイトの構造体
#pragma pack(1)
struct NB7大名情報型 {
	int* p大名武将; // その大名武将となる武将情報indexへのポインタが入っている。 大名武将なしなら 0x5694b0
	int 家紋番号; // 家紋のグラフィックの番号。大名家が有効ではない場合は、0xFF(=255)。一度も値がセッティングされていない大名家ならば-1が設定されているが、0xFFでも問題はない。
	WORD 友好ID[64]; // この値直接操作せず、set大名友好IDで操作すること(２つの大名の値を操作する必要があるため)。友好値を意味するID。indexは大名配列のindex。友好値については0〜Fであり、get友好値From友好IDで画面上で表示されている値と同じものとなる。 { 0, 10, 20, 30, 40, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 };
	BYTE 同盟残[64]; // この値直接操作せず、set大名同盟残で操作すること(２つの大名の値を操作する必要があるため)。同盟期間の残り月数。indexは大名配列のindex。この値は「本当に婚姻関係の姫が生存している」場合に限り、そのまま反映され、そうでない場合は、ゲーム上では半分のこの値の半分(切り上げ)となる
	BYTE 婚姻[64]; // この値直接操作せず、set大名婚姻で操作すること(２つの大名の値を操作する必要があるため)。婚姻有り無し。それぞれのindexは大名配列のindex。姫が存在していない場合は、このフラグを１に立てたとしても残月への効力はない。
	int 朝廷; // 0〜200
	int 朝廷MAX; // 200=0xC8が入っている
	int 鉄甲船; // 鉄甲船の数
	int 鉄甲船MAX; // 7が常に入っている
	int* p敵対大名; // p敵対大名。該当の大名配列へのポインタがそのまま入っている。
	int* p援軍申受大名; // 援軍要請をされた大名。該当の大名配列へのポインタがそのまま入っている。なしなら、 0x538eb8
	int* p援軍申込大名; // 援軍要請をした大名。該当の大名配列へのポインタがそのまま入っている。なしなら、 0x538eb8
	int* p不明5; // 不明なポインタ [74 91 53] = 0x539174が入っていることが多いようだ。
	BYTE プレイヤ担当:1; // 0なら担当ではない、1なら担当
	BYTE unknown13 : 1; // 不明
	BYTE 朝敵 : 1; // 朝敵なら1、そうでないなら。
	BYTE 鍛冶 : 1; // 鍛冶なら1、そうでないなら0
	BYTE 布教 : 1; // (キリスト教を)布教済みなら1、そうでないなら0
	BYTE unknown15 : 1; // 不明
	BYTE unknown16 : 1; // 不明
	BYTE 不明1 : 1; // 使われているが不明。何か大名勢力下に来る商人と関係しているようにも思われるが微妙に一致しない。あちこちの大名でONになったりOFFになったりしている
	BYTE unknown17; // ほとんど「4」が入っているようだが...不明
	int unknown18; // 不明。原則的には0と思われる。
	int* p居城; // 大名の居城となる城メモリデータへのポインタ(城配列への特定のindexの場所を直接さしている。
	int 旗番号; // 旗画像の番号が入っている。0-63といったように個数が大名最大数64個用意されている。
	int 旗画像MAX; // 原則0x3Fが入っている。
	int 大名番号; // 大名番号 配列のインデックス+1。1始まり。
	int 大名番号MAX; // 大名の最大数のこと。64。
};
#pragma pack()

BOOL isValidDaimyoID(int iDaimyoID);

// 大名IDからその大名の武将IDを取得する
int getBushouIDFromDaimyoID(int iDaimyoID);

// 大名Ptrから大名IDを取得する。
int getDaimyoIDFromDaimyoPtr(int* iDaimyoPtr);

// 大名IDから大名Ptrを取得する。
int* getDaimyoPtrFromDaimyoID(int iDaimyoID);

// 対象大名の大名武将を設定する
BOOL setDaimyoBushouID(int iDaimyoID, int iBushouID);

// 大名の居城を設定する
BOOL setDaimyoCastle(int iDaimyoID, int iCastleID);



int get友好値From友好ID(int i友好ID);

int get友好IDFrom友好値(int i友好値);

int get大名友好ID(int iDaimyoID1, int iDaimyoID2);
BOOL set大名友好ID(int iDaimyoID1, int iDaimyoID2, int i友好ID);

int get大名同盟残(int iDaimyoID1, int iDaimyoID2);
BOOL set大名同盟残(int iDaimyoID, int iDaimyoID2, int iMonth);

BOOL get大名婚姻(int iDaimyouID1, int iDaimyouID2);
BOOL set大名婚姻(int iDaimyouID1, int iDaimyouID2, BOOL 婚姻化);

BOOL set大名家紋番号(int iDaimyoID, int iKamonID);

/*
１つ目
00569848  48 23 54 00 00 00 00 00 00 00 05 00 05 00 05 00  H#T..........
00569858  05 00 05 00 0F 00 05 00 05 00 05 00 05 00 05 00  ........
00569868  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569878  05 00 05 00 05 00 05 00 07 00 05 00 05 00 05 00  ........
00569888  07 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569898  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
005698A8  05 00 05 00 05 00 05 00 05 00 00 00 00 00 00 00  ...........
005698B8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
005698C8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 24 00  ..............$.
005698D8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
005698E8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
005698F8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569908  00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00  ...............
00569918  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569928  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569938  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569948  00 00 00 00 00 00 00 00 00 00 00 00 C8 00 00 00  ............ﾈ...
00569958  00 00 00 00 07 00 00 00 B8 8E 53 00 B8 8E 53 00  .......ｸ惨.ｸ惨.
00569968  B8 8E 53 00 74 91 53 00 00 00 00 00 00 00 98 DD  ｸ惨.t全.......俤
00569978  5D 00 1E 00 00 00 3F 00 00 00 01 00 00 00 40 00  ]....?......@.
00569988  00 00 
２つ目
0056998A

                88 25 54 00 01 00 00 00 05 00 00 00 04 00  ..・T........
00569998  05 00 05 00 05 00 02 00 05 00 06 00 05 00 05 00  ........
005699A8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 06 00  ........
005699B8  05 00 05 00 05 00 05 00 05 00 07 00 05 00 05 00  ........
005699C8  05 00 09 00 05 00 05 00 05 00 05 00 05 00 05 00  .........
005699D8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
005699E8  05 00 05 00 05 00 05 00 05 00 05 00 00 00 00 00  ..........
005699F8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A08  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A18  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A28  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A38  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A48  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A58  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A68  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A78  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A88  00 00 00 00 00 00 00 00 00 00 50 00 00 00 C8 00  ..........P...ﾈ.
00569A98  00 00 00 00 00 00 07 00 00 00 B8 8E 53 00 B8 8E  .........ｸ惨.ｸ・
00569AA8  53 00 B8 8E 53 00 74 91 53 00 00 00 00 00 00 00  S.ｸ惨.t全.......
00569AB8  78 DC 5D 00 01 00 00 00 3F 00 00 00 02 00 00 00  xﾜ]....?......
00569AC8  40 00 00 00                                      @...



// 武田信玄の大名情報？ (19番目)

[ ] は武田信玄の武将情報へのポインタ
0056AEEC  [88 FD 54] 00 1D 00 00 00 05 00 06 00 05 00 05 00  ・T........
0056AEFC  07 00 05 00 05 00 05 00 06 00 05 00 05 00 05 00  ........
0056AF0C  05 00 03 00 0D 00 05 00 05 00 05 00 00 00 01 00  ..........
0056AF1C  04 00 05 00 05 00 05 00 0B 00 05 00 05 00 05 00  ........
0056AF2C  0D 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  .........
0056AF3C  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
0056AF4C  05 00 05 00 05 00 05 00 05 00 00 00 00 00 00 00  ...........
0056AF5C  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AF6C  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AF7C  00 00 00 00 00 00 17 00 00 00 00 00 00 00 00 00  ...............
0056AF8C  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AF9C  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AFAC  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AFBC  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AFCC  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AFDC  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056AFEC  00 00 00 00 00 00 00 00 6E 00 00 00 C8 00 00 00  ........n...ﾈ...
0056AFFC  00 00 00 00 07 00 00 00 2E B0 56 00 B8 8E 53 00  ........ｰV.ｸ惨.
0056B00C  B8 8E 53 00 74 91 53 00 00 00 00 00 00 00 38 D1  ｸ惨.t全.......8ﾑ
0056B01C  5D 00 04 00 00 00 3F 00 00 00 13 00 00 00 40 00  ]....?......@.
0056B02C  00 00 C8 17 55 00 1F 00 00 00 05 00 05 00 05 00  ..ﾈU.......
0056B03C  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
0056B04C  05 00 05 00 05 00 05 00 05 00 05 00 05 00 01 00  ........
0056B05C  00 00 05                                         ..
*/


/*
大名最初の７つほど
00569848  48 23 54 00 00 00 00 00 00 00 05 00 05 00 05 00  H#T..........
00569858  05 00 05 00 0F 00 05 00 05 00 05 00 05 00 05 00  ........
00569868  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569878  05 00 05 00 05 00 05 00 07 00 05 00 05 00 05 00  ........
00569888  07 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569898  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
005698A8  05 00 05 00 05 00 05 00 05 00 00 00 00 00 00 00  ...........
005698B8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
005698C8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 23 00  ..............#.
005698D8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
005698E8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
005698F8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569908  00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00  ...............
00569918  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569928  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569938  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569948  00 00 00 00 00 00 00 00 00 00 00 00 C8 00 00 00  ............ﾈ...
00569958  00 00 00 00 07 00 00 00 B8 8E 53 00 B8 8E 53 00  .......ｸ惨.ｸ惨.
00569968  B8 8E 53 00 74 91 53 00 00 00 00 00 00 00 98 DD  ｸ惨.t全.......俤
00569978  5D 00 1E 00 00 00 3F 00 00 00 01 00 00 00 40 00  ]....?......@.
00569988  00 00 88 25 54 00 01 00 00 00 05 00 00 00 04 00  ..・T........
00569998  05 00 05 00 05 00 02 00 05 00 06 00 05 00 05 00  ........
005699A8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 06 00  ........
005699B8  05 00 05 00 05 00 05 00 05 00 07 00 05 00 05 00  ........
005699C8  05 00 09 00 05 00 05 00 05 00 05 00 05 00 05 00  .........
005699D8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
005699E8  05 00 05 00 05 00 05 00 05 00 05 00 00 00 00 00  ..........
005699F8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A08  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A18  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A28  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A38  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A48  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A58  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A68  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A78  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569A88  00 00 00 00 00 00 00 00 00 00 50 00 00 00 C8 00  ..........P...ﾈ.
00569A98  00 00 00 00 00 00 07 00 00 00 B8 8E 53 00 B8 8E  .........ｸ惨.ｸ・
00569AA8  53 00 B8 8E 53 00 74 91 53 00 00 00 00 00 00 00  S.ｸ惨.t全.......
00569AB8  78 DC 5D 00 01 00 00 00 3F 00 00 00 02 00 00 00  xﾜ]....?......
00569AC8  40 00 00 00 C8 2D 54 00 04 00 00 00 05 00 04 00  @...ﾈ-T......
00569AD8  00 00 07 00 04 00 05 00 05 00 0A 00 05 00 05 00  ..........
00569AE8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569AF8  05 00 05 00 05 00 05 00 05 00 05 00 07 00 05 00  ........
00569B08  05 00 05 00 09 00 05 00 05 00 05 00 05 00 05 00  .........
00569B18  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569B28  05 00 05 00 05 00 05 00 05 00 05 00 05 00 00 00  .........
00569B38  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569B48  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569B58  00 00 00 22 00 00 00 00 00 00 00 00 00 00 00 00  ..."............
00569B68  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569B78  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569B88  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569B98  00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00  ...............
00569BA8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569BB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569BC8  00 00 00 00 00 00 00 00 00 00 00 00 46 00 00 00  ............F...
00569BD8  C8 00 00 00 00 00 00 00 07 00 00 00 B8 8E 53 00  ﾈ..........ｸ惨.
00569BE8  B8 8E 53 00 B8 8E 53 00 74 91 53 00 00 00 00 00  ｸ惨.ｸ惨.t全.....
00569BF8  00 00 E8 DB 5D 00 3D 00 00 00 3F 00 00 00 03 00  ..鞆].=...?....
00569C08  00 00 40 00 00 00 08 30 54 00 05 00 00 00 05 00  ..@...0T.....
00569C18  05 00 07 00 00 00 0B 00 02 00 05 00 02 00 05 00  .........
00569C28  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569C38  05 00 05 00 05 00 05 00 05 00 05 00 05 00 07 00  ........
00569C48  05 00 05 00 05 00 0B 00 05 00 05 00 05 00 05 00  ........
00569C58  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569C68  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569C78  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569C88  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569C98  00 00 0A 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569CA8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569CB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569CC8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569CD8  00 00 01 01 00 00 00 00 00 00 00 00 00 00 00 00  ..............
00569CE8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569CF8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569D08  00 00 00 00 00 00 00 00 00 00 00 00 00 00 78 00  ..............x.
00569D18  00 00 C8 00 00 00 00 00 00 00 07 00 00 00 92 9E  ..ﾈ..........寵
00569D28  56 00 B8 8E 53 00 B8 8E 53 00 74 91 53 00 00 00  V.ｸ惨.ｸ惨.t全...
00569D38  00 00 00 00 C8 DA 5D 00 13 00 00 00 3F 00 00 00  ....ﾈﾚ]....?...
00569D48  04 00 00 00 40 00 00 00 08 3C 54 00 06 00 00 00  ...@...<T....
00569D58  05 00 05 00 04 00 0B 00 00 00 04 00 05 00 03 00  .........
00569D68  02 00 07 00 05 00 05 00 05 00 07 00 05 00 05 00  ........
00569D78  05 00 05 00 07 00 05 00 05 00 05 00 05 00 05 00  ........
00569D88  07 00 05 00 05 00 05 00 0B 00 05 00 05 00 05 00  ........
00569D98  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569DA8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569DB8  05 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ...............
00569DC8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569DD8  00 00 00 0A 00 00 00 00 00 1C 00 00 00 1C 00 00  ..............
00569DE8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569DF8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569E08  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569E18  00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00  ...............
00569E28  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569E38  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569E48  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569E58  5A 00 00 00 C8 00 00 00 00 00 00 00 07 00 00 00  Z...ﾈ..........
00569E68  B8 8E 53 00 B8 8E 53 00 B8 8E 53 00 74 91 53 00  ｸ惨.ｸ惨.ｸ惨.t全.
00569E78  00 00 00 00 00 00 F8 D7 5D 00 21 00 00 00 3F 00  ......�ﾗ].!...?.
00569E88  00 00 05 00 00 00 40 00 00 00 48 44 54 00 07 00  .....@...HDT..
00569E98  00 00 05 00 05 00 05 00 02 00 04 00 00 00 05 00  ..........
00569EA8  07 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569EB8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569EC8  05 00 07 00 05 00 05 00 05 00 09 00 05 00 05 00  .........
00569ED8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569EE8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
00569EF8  05 00 05 00 00 00 00 00 00 00 00 00 00 00 00 00  ..............
00569F08  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F18  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F28  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F38  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F48  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F58  00 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00  ...............
00569F68  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F78  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F88  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00569F98  00 00 1E 00 00 00 C8 00 00 00 00 00 00 00 07 00  .....ﾈ........
00569FA8  00 00 0E 9C 56 00 B8 8E 53 00 B8 8E 53 00 74 91  ..弖.ｸ惨.ｸ惨.t・
00569FB8  53 00 00 00 00 00 00 00 A8 D9 5D 00 10 00 00 00  S.......ｨﾙ]....
00569FC8  3F 00 00 00 06 00 00 00 40 00 00 00 C8 48 54 00  ?......@...ﾈHT.
00569FD8  09 00 00 00 0F 00 02 00 05 00 05 00 05 00 05 00  ..........
00569FE8  00 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  .........
00569FF8  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
0056A008  05 00 05 00 07 00 05 00 05 00 05 00 09 00 05 00  .........
0056A018  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
0056A028  05 00 05 00 05 00 05 00 05 00 05 00 05 00 05 00  ........
0056A038  05 00 05 00 05 00 00 00 00 00 00 00 00 00 00 00  .............
0056A048  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A058  00 00 00 00 23 00 00 00 00 00 00 00 00 00 00 00  ....#...........
0056A068  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A078  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A088  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A098  00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00  ...............
0056A0A8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A0B8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A0C8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0056A0D8  00 00 00 00 0A 00 00 00 C8 00 00 00 00 00 00 00  ........ﾈ.......
0056A0E8  07 00 00 00 B8 8E 53 00 B8 8E 53 00 B8 8E 53 00  ...ｸ惨.ｸ惨.ｸ惨.
0056A0F8  74 91 53 00 00 00 00 00 00 00 58 DB 5D 00 08 00  t全.......Xﾛ]..
0056A108  00 00 3F 00 00 00 07 00 00 00 40 00 00 00        ..?......@...

*/