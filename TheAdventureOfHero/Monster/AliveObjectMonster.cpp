#include "AliveObjectMonster.h"

AliveObjectMonster::AliveObjectMonster() {
	HP_ = 10;
	ATK_ = 10;
	DEF_ = 3;
	monster_type_ = NONE_TYPE;
};

AliveObjectMonster::AliveObjectMonster(int HP, int ATK, int DEF, MONSTER_TYPE monster_type) {
	HP_ = HP;
	ATK_ = ATK;
	DEF_ = DEF;
	monster_type_ = monster_type;
};

AliveObjectMonster::~AliveObjectMonster() {

};

bool AliveObjectMonster::AttackNormal() {
	return true;
};

bool AliveObjectMonster::CheckState() {
	if(HP_ > 0)
		return true;
	else 
		return false;
};