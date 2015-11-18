//For Alive Object;Monster.
#pragma once

#include "../Base/BaseAliveObject.h"

class AliveObjectMonster : public IBaseAliveObject {
public:
	AliveObjectMonster();
	AliveObjectMonster(int HP, int ATK, int DEF);
	virtual ~AliveObjectMonster();

	virtual bool AttackNormal();

	// when HP 0 monster dead
	virtual bool CheckState();

	//getter setter
	inline int GetHP() { return HP_; }
	inline void SetHP(int HP) { HP_ = HP; }

	inline int GetAttack() { return ATK_; }
	inline void SetAttack(int ATK) { ATK_ = ATK; }

	inline int GetDeffense() { return DEF_; }
	inline void SetDeffense(int DEF) { DEF_ = DEF; }

private:
//capabilities 
	int HP_;
	//int SP_;
	int ATK_;
	int DEF_;
//items
	//���� ����� ����*2
	//����ġ�� ����� ����*1.5
	//����ġ�� ���� ���� ������ ����
};