//For Alive Object;Hero.

#ifndef ALIVE_OBJECT_HERO_H
#define ALIVE_OBJECT_HERO_H

#include "../Base/BaseAliveObject.h"

class AliveObjectHero : public IBaseAliveObject {
	AliveObjectHero();
	AliveObjectHero(int HP, int SP, int ATK, int DEF, int LEV, int Gold);
	~AliveObjectHero();

	virtual bool AttackNormal();
	bool AttackSpecial();
	bool RunAway();
	
	// When hero act end, check state
	// Forcibly move to village when SP 0,
	// Fail mission when HP 0 or Gold ran out
	void CheckState();

private:
//capabilities 
	int HP_;
	int SP_;
	int ATK_;
	int DEF_;
	int LEV_;
//items
	int Gold_;
};

#endif