//For Alive Object;Monster.
#pragma once

#include "../Base/BaseAliveObject.h"

//set monster type by enum
enum MONSTER_TYPE {
	NONE_TYPE = 0,
	MONSTER_KOBOLD = 1,
	MONSTER_GOBLIN = 2,
	MONSTER_OGRE = 3,
};

class AliveObjectMonster : public IBaseAliveObject {
public:
	AliveObjectMonster();
	AliveObjectMonster(int HP, int ATK, int DEF, int Level, MONSTER_TYPE monster_type, char* monster_name);
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

	inline int GetLevel() { return Level_; }
	inline void SetLevel(int LEV) { Level_ = LEV; }

	inline MONSTER_TYPE GetMonsterType() { return monster_type_; }
	inline void SetMonsterType(MONSTER_TYPE monster_type) { monster_type_ = monster_type; }

	inline char* GetName() { return monster_name_; }
private:
	//capabilities 
	int HP_;
	//int SP_;
	int ATK_;
	int DEF_;
	int Level_;

	MONSTER_TYPE monster_type_;
	char* monster_name_;
//items
	//���� ����� ����*2
	//����ġ�� ����� ����*1.5
	//����ġ�� ���� ���� ������ ����
};