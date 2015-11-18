#include "AliveObjectMonster.h"

AliveObjectMonster::AliveObjectMonster() {
	HP_ = 10;
	ATK_ = 10;
	DEF_ = 3;
};

AliveObjectMonster::AliveObjectMonster(int HP, int ATK, int DEF) {
	HP_ = HP;
	ATK_ = ATK;
	DEF_ = DEF;
};

AliveObjectMonster::~AliveObjectMonster() {

};

bool AliveObjectMonster::AttackNormal() {
	return true;
};

bool AliveObjectMonster::CheckState() {
	return true;
};