//For Alive Object;Hero.

#pragma once

#include "../Base/BaseAliveObject.h"

class AliveObjectHero : public IBaseAliveObject {
public:
	AliveObjectHero();
	AliveObjectHero(int HP, int SP, int ATK, int DEF, int LEV, int Gold);
	virtual ~AliveObjectHero();

	virtual bool AttackNormal();
	bool AttackSpecial();
	bool RunAway();
	
	// When hero act end, check state
	// Forcibly move to village when SP 0,
	// Fail mission when HP 0 or Gold ran out
	void CheckState(int place_type);
	const char* hero_name_;

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
