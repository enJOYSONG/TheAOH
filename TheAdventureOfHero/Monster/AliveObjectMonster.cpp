#include "AliveObjectMonster.h"

AliveObjectMonster::AliveObjectMonster() {
	HP_ = 10;
	ATK_ = 10;
	DEF_ = 3;
	Level_ = 1;
	monster_type_ = NONE_TYPE;
	monster_name_ = "";
};

AliveObjectMonster::AliveObjectMonster(int HP, int ATK, int DEF, int Level, MONSTER_TYPE monster_type, char* monster_name) {
	HP_ = HP;
	ATK_ = ATK;
	DEF_ = DEF;
	Level_ = Level;
	monster_type_ = monster_type;
	monster_name_ = monster_name;
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