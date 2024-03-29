#include <string>

#include "data_game_struct.h"
#include "data_yakusyoku_struct.h"
#include "mng_役職列挙.h"
#include "mng_役職情報.h"

using namespace std;
using namespace 将星録::列挙;

using namespace System::Collections::Generic;

役職情報型::役職情報型(int 役職配列IX)
{
	if (isValidYakusyokuID(役職配列IX)) {
		this->役職配列IX = 役職配列IX;
	}
	else {
		throw gcnew System::ArgumentException("役職配列IXが不正です。");
	}
}

String^ 役職情報型::役職名::get()
{
	return gcnew String(nb7役職情報[役職配列IX].役職名);
}

void 役職情報型::役職名::set(String^ value) {
	if (String::IsNullOrEmpty(value)) {
		throw gcnew System::ArgumentNullException("役職名がnullです。");
	}
	string native_value = to_native_string(value);
	if (native_value.size() <= 11) { // ASCIIベースで11バイト以内
		setYakusyokuName(役職配列IX, native_value);
	}
	else {
		throw gcnew System::ArgumentException("役職名が長すぎます。");
	}
}

int 役職情報型::役位::get()
{
	return nb7役職情報[役職配列IX].役位;
}

void 役職情報型::役位::set(int value) {
	if (0 <= value && value < 最大数::役職情報::配列数) {
		nb7役職情報[役職配列IX].役位 = value;
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("役位が不正です。");
	}
}

int 役職情報型::所有大名配列IX::get()
{
	return getDaimyoIDFromYakusyokuID(役職配列IX);;
}

void 役職情報型::所有大名配列IX::set(int value) {
	if (isValidDaimyoID(value) || value == 0xFFFF) { // 0xFFFF は朝廷を意味する
		int ret = setDaimyoIDToYakusyokuID(役職配列IX, value);
		if (ret == 0) {
			throw gcnew System::ArgumentException("所有大名配列IXが不正です");
		}
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("所有大名配列IXが不正です。");
	}
}

