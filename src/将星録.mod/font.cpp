#include <windows.h>
#include <winuser.h>
#include <stdio.h>

#include "window.h"
#include "process.h"



/*
005056B5   68 04EE5300      PUSH Nobunaga.0053EE04
005056BA   53               PUSH EBX
005056BB   53               PUSH EBX
005056BC   53               PUSH EBX
005056BD   53               PUSH EBX
005056BE   68 80000000      PUSH 80
005056C3   53               PUSH EBX
005056C4   53               PUSH EBX
005056C5   53               PUSH EBX
005056C6   53               PUSH EBX
005056C7   53               PUSH EBX
005056C8   53               PUSH EBX
005056C9   6A 08            PUSH 8
005056CB   6A F0            PUSH -10
 */


void onFontInitialize() {
    OutputDebugString("onFontInitialize\r\n");
	strcpy_s((char*)0x53EE04, 11, "���� ����");
}

