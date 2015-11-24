#include <iostream>
#include "AliveObjectHero.h"

using namespace std;
AliveObjectHero::AliveObjectHero() {
	HP_ = 100;
	SP_ = 100;
	ATK_ = 10;
	DEF_ = 10;
	LEV_ = 1;
	Gold_ = 100;

	HP_ALL_ = HP_;
	SP_ALL_ = SP_;

	hero_name_ = "용사 1";

	cout<<hero_name_<<" 생성"<<endl;
};

AliveObjectHero::AliveObjectHero(int HP, int SP, int ATK, int DEF, int LEV, int Gold) {
	HP_ = HP;
	SP_ = SP;
	ATK_ = ATK;
	DEF_ = DEF;
	LEV_ = LEV;
	Gold_ = Gold;

	HP_ALL_ = HP_;
	SP_ALL_ = SP_;
};

AliveObjectHero::~AliveObjectHero() {

};

bool AliveObjectHero::AttackNormal() {
	return true;
};

bool AliveObjectHero::CheckState() {
	if(HP_ > 0 && Gold_ >= 0)
		return true;
	else 
		return false;
};

bool AliveObjectHero::AttackSpecial() {
	return true;
};

bool AliveObjectHero::RunAway() {
	return true; 
};
