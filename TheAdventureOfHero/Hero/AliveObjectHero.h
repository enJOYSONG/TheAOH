//For Alive Object;Hero.

#pragma once

#include "../Base/BaseAliveObject.h"

class AliveObjectHero : public IBaseAliveObject {
public:
	AliveObjectHero();
	AliveObjectHero(int HP, int SP, int ATK, int DEF, int LEV, int Gold);
	virtual ~AliveObjectHero();

	virtual bool AttackNormal();
	virtual bool CheckState();
	bool AttackSpecial();
	bool RunAway();
	
	// return hero name
	inline const char* GetName() { return hero_name_; }

	// Forcibly move to village when SP 0,
	// Fail mission when HP 0 or Gold ran out

	//getter setter
	inline int GetHPAll() { return HP_ALL_; }
	inline void SetHPAll(int HP_All) { HP_ALL_ = HP_All; }

	inline int GetSPAll() { return SP_ALL_; }
	inline void SetSPAll(int SP_All) { SP_ALL_ = SP_All; }

	inline int GetHP() { return HP_; }
	inline void SetHP(int HP) { HP_ = HP; }

	inline int GetSP() { return SP_; }
	inline void SetSP(int SP) { SP_ = SP; }

	inline int GetAttack() { return ATK_; }
	inline void SetAttack(int ATK) { ATK_ = ATK; }

	inline int GetDeffense() { return DEF_; }
	inline void SetDeffense(int DEF) { DEF_ = DEF; }

	inline int GetLevel() { return LEV_; }
	inline void SetLevel(int LEV) { LEV_ = LEV; }

	inline int GetGold() { return Gold_; }
	inline void SetGold(int GOLD) { Gold_ = GOLD; }

private:
//capabilities save
	int HP_ALL_;
	int SP_ALL_;

//capabilities 
	int HP_;
	int SP_;
	int ATK_;
	int DEF_;
	int LEV_;
//items
	int Gold_;
//Name
	const char* hero_name_;
};
