#include "dllextern.h"
#include "process.h"
#include "loadmod.h"
#include "output_debug_stream.h"
#include "dllextern.h"
#include "loadmod.h"
#include "loadantidebug.h"

void onInitialize() {
    loadAntiDebug();
    loadNB7Mod();

    Mod_onInitialize();
}


void onMciSendCommand() {
}


void onFinalize() {
    freeNB7Mod();

    OutputDebugStream("�����^�̏I��\n");
}