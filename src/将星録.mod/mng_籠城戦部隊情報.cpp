#include <string>
#include <algorithm>

#include <vector>
#include "data_game_struct.h"
#include "castle_battle_attack_heisuu_sum.h"
#include "castle_battle_defend_heisuu_sum.h"
#include "mng_籠城戦部隊情報.h"
#include "mng_文字列変換.h"

using namespace std;
using namespace 将星録::列挙;
using namespace 将星録::籠城戦;
using namespace System::Collections::Generic;

/*
-----------------------------------------------------------------------
   攻撃部隊
-----------------------------------------------------------------------
*/


攻撃部隊情報型::攻撃部隊情報型(int 部隊配列IX)
{
	if (0 <= 部隊配列IX && 部隊配列IX < 最大数::籠城戦::攻撃部隊情報::配列数) {
		this->部隊配列IX = 部隊配列IX;
	}
	else {
		throw gcnew System::ArgumentException("部隊配列IXが不正です。");
	}
}

int 攻撃部隊情報型::部隊番号::get()
{
	return nb7籠城戦攻撃側部隊情報[部隊配列IX].部隊番号;
}

int 攻撃部隊情報型::指揮武将配列IX::get()
{
	return getBushouIDFromBushouPtr(nb7籠城戦攻撃側部隊情報[部隊配列IX].p指揮武将);
}


int 攻撃部隊情報型::兵数::get()
{
	return nb7籠城戦攻撃側部隊情報[部隊配列IX].兵数;
}

void 攻撃部隊情報型::兵数::set(int value) {
	if (0 <= value && value <= 1000) {
		nb7籠城戦攻撃側部隊情報[部隊配列IX].兵数 = value;
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("兵数が不正です。");
	}
}

int 攻撃部隊情報型::行動済::get()
{
	return nb7籠城戦攻撃側部隊情報[部隊配列IX].行動済;
}

void 攻撃部隊情報型::行動済::set(int value) {
	if (0 <= value && value <= 1) {
		nb7籠城戦攻撃側部隊情報[部隊配列IX].行動済 = value;
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("行動済が不正です。");
	}
}

int 攻撃部隊情報型::現在Ｘ座標::get()
{
	return nb7籠城戦攻撃側部隊情報[部隊配列IX].現在Ｘ座標;
}

int 攻撃部隊情報型::現在Ｙ座標::get()
{
	return nb7籠城戦攻撃側部隊情報[部隊配列IX].現在Ｙ座標;
}


/*
-----------------------------------------------------------------------
   防御部隊
-----------------------------------------------------------------------
*/
防御部隊情報型::防御部隊情報型(int 部隊配列IX)
{
	if (0 <= 部隊配列IX && 部隊配列IX < 最大数::籠城戦::防御部隊情報::配列数) {
		this->部隊配列IX = 部隊配列IX;
	}
	else {
		throw gcnew System::ArgumentException("部隊配列IXが不正です。");
	}
}

int 防御部隊情報型::部隊番号::get()
{
	return nb7籠城戦防御側部隊情報[部隊配列IX].部隊番号;
}

int 防御部隊情報型::指揮武将配列IX::get()
{
	return getBushouIDFromBushouPtr(nb7籠城戦防御側部隊情報[部隊配列IX].p指揮武将);
}

int 防御部隊情報型::兵数::get()
{
	return nb7籠城戦防御側部隊情報[部隊配列IX].兵数;
}

void 防御部隊情報型::兵数::set(int value) {
	if (0 <= value && value <= 1000) {
		nb7籠城戦防御側部隊情報[部隊配列IX].兵数 = value;
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("兵数が不正です。");
	}
}

int 防御部隊情報型::行動残数::get()
{
	return nb7籠城戦防御側部隊情報[部隊配列IX].行動残数;
}

void 防御部隊情報型::行動残数::set(int value) {
	if (0 <= value && value <= 9) {
		nb7籠城戦防御側部隊情報[部隊配列IX].行動残数 = value;
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("行動残数が不正です。");
	}
}

int 防御部隊情報型::混乱::get()
{
	return nb7籠城戦防御側部隊情報[部隊配列IX].混乱;
}

void 防御部隊情報型::混乱::set(int value) {
	if (0 <= value && value <= 1) {
		nb7籠城戦防御側部隊情報[部隊配列IX].混乱 = value;
	}
	else {
		throw gcnew System::ArgumentOutOfRangeException("混乱が不正です。");
	}
}

/*
int 防御部隊情報型::現在Ｘ座標::get()
{
	return nb7籠城戦防御側部隊情報[部隊配列IX].現在Ｘ座標;
}

int 防御部隊情報型::現在Ｙ座標::get()
{
	return nb7籠城戦防御側部隊情報[部隊配列IX].現在Ｙ座標;
}
*/