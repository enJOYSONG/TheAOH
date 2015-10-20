#include "AliveObjectMonster.h"

AliveObjectMonster::AliveObjectMonster() {

};

AliveObjectMonster::AliveObjectMonster(int HP, int SP, int ATK, int DEF, int Gold) {
	HP_ = HP;
	SP_ = SP;
	ATK_ = ATK;
	DEF_ = DEF;
	Gold_ = Gold;
};

AliveObjectMonster::~AliveObjectMonster() {

};

bool AliveObjectMonster::AttackNormal() {
	return true;
};

void AliveObjectMonster::CheckState() {

};