#include <windows.h>
#include <string>
#include <vector>
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
#include "hook_functions_direct.h"
#include "bushou_albedo.h"

#include "mng_éñ.h"

using namespace std;

int testFlag = 0;

void doGameTest() {
	testFlag = 1;
	for (int i = 0; i < Åå::«îñ::zñ; i++) {
		OutputDebugStream("óÔ:%d ", nb7«îñ[i].óÔ);
		if (isValidBushouID(i)) {
			auto ©¼ = nb7«îñ[i].©¼;
			OutputDebugStream("%s\n", ©¼);
		}
		else {
			OutputDebugStream("\n");
		}
	}
	/*
	for (int iCastleID = 0; iCastleID < Åå::éîñ::zñ; iCastleID++) {
		if (nb7éîñ[iCastleID].é¼ == "l¼"s) {
			OutputDebugStream("l¼ÌÏC:%d\n", (int)nb7éîñ[iCastleID].ÏCóÔ);
			OutputDebugStream("l¼ÌÏCU:%d\n", (int)nb7éîñ[iCastleID].ÏCU);
			OutputDebugStream("l¼ÌÏCH:%d\n", (int)nb7éîñ[iCastleID].unused1);
		}
	}
	*/

	/*
	for (int iBushouID = 0; iBushouID < Åå::«îñ::zñ; iBushouID++) {

		if (getBushou©¼FromBushouID(iBushouID) == "DcM·") {
			OutputDebugStream("DcM·Ì«Ô %x\n", iBushouID);
		}
		if (getBushou©¼FromBushouID(iBushouID) == "¡ì`³") {
			OutputDebugStream("¡ì`³Ì«Ô %x\n", iBushouID);
		}
		if (getBushou©¼FromBushouID(iBushouID) == "cMº") {
			OutputDebugStream("cMºÌ«Ô %x\n", iBushouID);
		}
	}
	*/

	/*
	for (int iBushouID = 0; iBushouID < Åå::«îñ::zñ; iBushouID++) {
		OutputDebugStream(nb7«îñ[iBushouID].©¼);
		OutputDebugStream("\n");

		if (getBushoucFromBushouID(iBushouID) == "É") {
			OutputDebugStream("«ID:" + getBushou©¼FromBushouID(iBushouID));
			OutputDebugStream("­¡:%d ", nb7«îñ[iBushouID].­¡);
			OutputDebugStream("í¬:%d ", nb7«îñ[iBushouID].í¬);
			OutputDebugStream("md:%d ", nb7«îñ[iBushouID].qd);
			OutputDebugStream("EÆ:%d ", nb7«îñ[iBushouID].EÆ);
			OutputDebugStream("\n");

			for (int iKahouID = 0; iKahouID < Åå::Æóîñ::zñ; iKahouID++) {
				if (string(nb7Æóîñ[iKahouID].Æó¼).find("¥¦") != string::npos) {
					// strcpy(nb7Æóîñ[iKahouID].Æó¼, "¨¥¦©§ª");
					// setBushouIDToKahouID(iKahouID, iBushouID);
				}
			}
		}

	}
	*/

	/*
	for (int iKahouID = 0; iKahouID < Åå::Æóîñ::zñ; iKahouID++) {
		OutputDebugStream("Æó¼:%s ", nb7Æóîñ[iKahouID].Æó¼);
		// OutputDebugStream("ºÈøÊ:%d ", nb7Æóîñ[iKahouID].ºÈøÊ);
		// OutputDebugStream(":%d ", nb7Æóîñ[iKahouID].);
		// OutputDebugStream("æ:%d ", nb7Æóîñ[iKahouID].æ);
		// OutputDebugStream("ã¸\Íl:%d ", nb7Æóîñ[iKahouID].\Íã¸);
		// OutputDebugStream("ÆóíÞ:%d", nb7Æóîñ[iKahouID].íÞ);
		// if (nb7Æóîñ[iKahouID].ìØ) OutputDebugStream("s¾3:%d", nb7Æóîñ[iKahouID].ìØ);
		int iBushouID = getBushouIDFromKahouID(iKahouID);
		if (0 <= iBushouID && iBushouID < Åå::«îñ::zñ) {
			// OutputDebugStream("LÒ:%s ", nb7«îñ[iBushouID].©¼);
		} else {
			OutputDebugStream("LÒ:%x\n", nb7Æóîñ[iKahouID].pLÒ);
		}	
		// OutputDebugStream("ÆóÔ:%d ", nb7Æóîñ[iKahouID].ÆóÔ);
		// OutputDebugStream("ÆóÅå:%d ", nb7Æóîñ[iKahouID].ÆóÔMAX);
		// OutputDebugStream("\n");
	}
	*/

	/*
	for (int iKanniID = 0; iKanniID < Åå::¯Êîñ::zñ; iKanniID++) {
		OutputDebugStream("%s", nb7¯Êîñ[iKanniID].¯Ê¼);
		OutputDebugStream("KÊ:%d\n", nb7¯Êîñ[iKanniID].KÊ);
		OutputDebugStream("¯ÊÔ:%d ", nb7¯Êîñ[iKanniID].¯ÊÔ);
		OutputDebugStream("\n");
		int iBushouID = getBushouIDFromKanniID(iKanniID);
		if (0 <= iBushouID && iBushouID < Åå::«îñ::zñ) {

			OutputDebugStream("LÒ:%s ", nb7«îñ[iBushouID].©¼);
		}
	}
	*/

	/*
	for (int iYakusyokuID = 0; iYakusyokuID < Åå::ðEîñ::zñ; iYakusyokuID++) {
		OutputDebugStream("ðE¼:%s ", nb7ðEîñ[iYakusyokuID].ðE¼);
		OutputDebugStream("ðEÔ:%d ", nb7ðEîñ[iYakusyokuID].ðEÔ);
		OutputDebugStream("ðÊ:%d ", nb7ðEîñ[iYakusyokuID].ðÊ);
		int iBushouID = getBushouIDFromYakusyokuID(iYakusyokuID);
		OutputDebugStream("%d", iBushouID);
		if ( 0 <= iBushouID && iBushouID < Åå::«îñ::zñ) {

			OutputDebugStream("LÒ:%s ", nb7«îñ[iBushouID].©¼);
		}
		OutputDebugStream("\n");
	}
	*/

	/*
	for (int iCastleID = 0; iCastleID < Åå::éîñ::zñ; iCastleID++) {
		OutputDebugStream("é¼:%s", nb7éîñ[iCastleID].é¼);
		OutputDebugStream(getéÌ(iCastleID) + "\n");
	}
	*/

	/*

	for (int iUnitID = 0; iUnitID < Åå::jbgîñ::zñ; iUnitID++) {
		int iBushouID = getBushouIDFromUnitID(iUnitID);
		if (iBushouID != 0xFFFF) {
			OutputDebugStream("jbgÔ:%d ", nb7jbgîñ[iUnitID].jbgÔ);
			int iBushouID = getBushouIDFromUnitID(iUnitID);
			if (isValidBushouID(iBushouID)) {
				OutputDebugStream("%s", nb7«îñ[iBushouID].©¼);
				OutputDebugStream("jbgåC:%d \n", nb7jbgîñ[iUnitID].åC);
				OutputDebugStream("jbgSbD:%d \n", nb7jbgîñ[iUnitID].SbD);
				OutputDebugStream("jbgàK:%d \n", nb7jbgîñ[iUnitID].àK);
				OutputDebugStream("jbgºÆ:%d \n", nb7jbgîñ[iUnitID].ºÆ);
				int pNextUnit = (int)nb7jbgîñ[iUnitID].pÌjbg;
				int iNextUnitID = getUnitIDFromUnitPtr(nb7jbgîñ[iUnitID].pÌjbg);
				if (isValidUnitID(iNextUnitID)) {
					OutputDebugStream("Ìjbg:%d \n", getUnitIDFromUnitPtr(nb7jbgîñ[iUnitID].pÌjbg));
				} else {
					OutputDebugStream("ÌjbgÍÈµ:%x\n", nb7jbgîñ[iUnitID].pÌjbg);
				}
			}
		}
	}
	*/

	/*
	auto ret = getQ[æÊXe[^X();
	OutputDebugStream("Q[æÊXe[^X: %d", (int)ret);

	for (int iUnitID = 0; iUnitID < Åå::jbgîñ::zñ; iUnitID++) {
		int iBushouID = getBushouIDFromUnitID(iUnitID);
		if (0 <= iBushouID && iBushouID < Åå::«îñ::zñ) {
			if (getBushou©¼FromBushouID(iBushouID) == getArubedoSeiMei()) {

				nb7jbgîñ[iUnitID].SbD = 1;
			}
		}
	}
	*/

	/*
	for (int iDaimyoID = 0; iDaimyoID < Åå::jbgîñ::zñ; iDaimyoID++) {
		int iBushouID = getBushouIDFromDaimyoID(iDaimyoID);
		if ( isValidBushouID(iBushouID) ) {
			OutputDebugStream("©¼:%s\n", nb7«îñ[iBushouID].©¼);
		}
	}
	*/

	/*
	for (int iDaimyouID = 0; iDaimyouID < Åå::å¼îñ::zñ; iDaimyouID++) {
		// if (nb7å¼îñ[iDaimyouID].vCS > 0) {
		if (nb7å¼îñ[iDaimyouID].unknown17) {
			OutputDebugStream("Ô:%d\t", iDaimyouID);
			OutputDebugStream("å¼:%s\n", nb7å¼îñ[iDaimyouID].på¼«);
			OutputDebugStream("unknown17:%d\n", nb7å¼îñ[iDaimyouID].unknown17);
		}
		if (nb7å¼îñ[iDaimyouID].unknown18) {
			OutputDebugStream("Ô:%d\t", iDaimyouID);
			OutputDebugStream("å¼:%s\n", nb7å¼îñ[iDaimyouID].på¼«);
			OutputDebugStream("unknown18:%d\n", nb7å¼îñ[iDaimyouID].unknown18);
		}
	}
	*/
}

