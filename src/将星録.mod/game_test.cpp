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
#include "hook_functions_direct.h"
#include "bushou_albedo.h"

#include "mng_éîñ.h"

using namespace std;

int testFlag = 0;

void doGameTest() {
	testFlag = 1;

	using namespace System::Collections::Generic;
	List<éîñ^^>^ list = gcnew List<éîñ^^>(Åå::éîñ::zñ);
	for (int i = 0; i < Åå::éîñ::zñ; i++) {
		list->Add(gcnew éîñ^(i));
	}

	auto rlist = list->AsReadOnly();

	for each (auto r in rlist) {
		if (r->zñIX == Åå::éîñ::zñ - 1) {
			auto n1 = r->é¼;
			r->é¼ = n1;
			auto n2 = r->é¼;
			if (n1 == n2) {
				OutputDebugStream("é¼Æé¼ªêv\n");
			}
			else {
				OutputDebugStream("é¼Æé¼ªsêv\n");
			}

			auto h1 = r->º;
			r->º = h1;
			auto h2 = r->º;

			if (h1 == h2) {
				OutputDebugStream("ºÆºªêv\n");
			}
			else {
				OutputDebugStream("ºÆºªsêv\n");
			}

			auto h2_a = r->ºÆ;
			r->ºÆ = h2_a;
			auto h2_b = r->ºÆ;

			if (h2_a == h2_b) {
				OutputDebugStream("ºÆÆºÆªêv\n");
			}
			else {
				OutputDebugStream("ºÆÆºÆªsêv\n");
			}

			auto h3_a = r->¤l;
			r->¤l = h3_a;
			auto h3_b = r->¤l;

			if (h3_a == h3_b) {
				OutputDebugStream("¤lÆ¤lªêv\n");
			}
			else {
				OutputDebugStream("¤lÆ¤lªsêv\n");
			}

			auto h4_a = r->éKÍ;
			r->éKÍ = h4_a;
			auto h4_b = r->éKÍ;

			if (h4_a == h4_b) {
				OutputDebugStream("éKÍÆéKÍªêv\n");
			}
			else {
				OutputDebugStream("éKÍÆéKÍªsêv\n");
			}

			auto h5_a = r->åC;
			r->åC = h5_a;
			auto h5_b = r->åC;

			if (h5_a == h5_b) {
				OutputDebugStream("åCÆåCªêv\n");
			}
			else {
				OutputDebugStream("åCÆåCªsêv\n");
			}

			auto h6_a = r->ÏCU;
			r->ÏCU = h6_a;
			auto h6_b = r->ÏCU;

			if (h6_a == h6_b) {
				OutputDebugStream("ÏCUÆÏCUªêv\n");
			}
			else {
				OutputDebugStream("ÏCUÆÏCUªsêv\n");
			}

			auto h7_a = r->ÏCóÔ;
			r->ÏCóÔ = h7_a;
			auto h7_b = r->ÏCóÔ;

			if (h7_a == h7_b) {
				OutputDebugStream("ÏCóÔÆÏCóÔªêv\n");
			}
			else {
				OutputDebugStream("ÏCóÔÆÏCóÔªsêv\n");
			}

			auto h8_a = r->º;
			r->º = h8_a;
			auto h8_b = r->º;

			if (h8_a == h8_b) {
				OutputDebugStream("ºÆºªêv\n");
			}
			else {
				OutputDebugStream("ºÆºªsêv\n");
			}

			auto h9_a = r->Rn;
			r->Rn = h9_a;
			auto h9_b = r->Rn;

			if (h9_a == h9_b) {
				OutputDebugStream("RnÆRnªêv\n");
			}
			else {
				OutputDebugStream("RnÆRnªsêv\n");
			}

			auto h10_a = r->àK;
			r->àK = h10_a;
			auto h10_b = r->àK;

			if (h10_a == h10_b) {
				OutputDebugStream("àKÆàKªêv\n");
			}
			else {
				OutputDebugStream("àKÆàKªsêv\n");
			}

			auto h11_a = r->SC;
			r->SC = h11_a;
			auto h11_b = r->SC;

			if (h11_a == h11_b) {
				OutputDebugStream("SCÆSCªêv\n");
			}
			else {
				OutputDebugStream("SCÆSCªsêv\n");
			}

			auto h12_a = r->hä;
			r->hä = h12_a;
			auto h12_b = r->hä;

			if (h12_a == h12_b) {
				OutputDebugStream("häÆhäªêv\n");
			}
			else {
				OutputDebugStream("häÆhäªsêv\n");
			}

			auto h13_a = r->ÏCUÚWézñIX;
			r->ÏCUÚWézñIX = h13_a;
			auto h13_b = r->ÏCUÚWézñIX;

			if (h13_a == h13_b) {
				OutputDebugStream("ÏCUÚWézñIXÆÏCUÚWézñIXªêv\n");
			}
			else {
				OutputDebugStream("ÏCUÚWézñIXÆÏCUÚWézñIXªsêv\n");
			}

			r->ÏCUÚWézñIX = 0xFFFF;
			auto h13_c = r->ÏCUÚWézñIX;

			if (h13_c == 0xFFFF) {
				OutputDebugStream("ÏCUÚWézñIXÆ0xFFFFªêv\n");
			}
			else {
				OutputDebugStream("ÏCUÚWézñIXÆ0xFFFFªsêv\n");
			}

			auto h14_a = r->®å¼zñIX;
			r->®å¼zñIX = h14_a;
			auto h14_b = r->®å¼zñIX;

			if (h14_a == h14_b) {
				OutputDebugStream("®å¼zñIXÆ®å¼zñIXªêv\n");
			}
			else {
				OutputDebugStream("®å¼zñIXÆ®å¼zñIXªsêv\n");
			}

			r->®å¼zñIX = 0xFFFF;
			auto h14_c = r->®å¼zñIX;

			if (h14_c == 0xFFFF) {
				OutputDebugStream("®å¼zñIXÆ0xFFFFªêv\n");
			}
			else {
				OutputDebugStream("®å¼zñIXÆ0xFFFFªsêv\n");
			}


			auto h15_a = r->JnjbgzñIX;
			r->JnjbgzñIX = h15_a;
			auto h15_b = r->JnjbgzñIX;

			if (h15_a == h15_b) {
				OutputDebugStream("JnjbgzñIXÆJnjbgzñIXªêv\n");
			}
			else {
				OutputDebugStream("JnjbgzñIXÆJnjbgzñIXªsêv\n");
			}
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

