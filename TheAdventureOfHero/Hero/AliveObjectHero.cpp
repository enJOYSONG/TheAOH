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
};

AliveObjectHero::~AliveObjectHero() {

};

bool AliveObjectHero::AttackNormal() {
	return true;
};

bool AliveObjectHero::AttackSpecial() {
	return true;
};

bool AliveObjectHero::RunAway() {
	return true; 
};

void AliveObjectHero::CheckState(int place_type) {
	cout << place_type << endl;
};