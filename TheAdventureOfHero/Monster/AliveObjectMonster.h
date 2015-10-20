//For Alive Object;Monster.
#pragma once

#include "../Base/BaseAliveObject.h"

class AliveObjectMonster : public IBaseAliveObject {
public:
	AliveObjectMonster();
	AliveObjectMonster(int HP, int SP, int ATK, int DEF, int Gold);
	virtual ~AliveObjectMonster();

	virtual bool AttackNormal();

	// when HP 0 monster dead
	void CheckState();

private:
//capabilities 
	int HP_;
	int SP_;
	int ATK_;
	int DEF_;
//items
	int Gold_;
};