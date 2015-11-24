#pragma once

// Battle Manager!

class EntityManager;
class BattleManager {
public:
	BattleManager();
	~BattleManager(){};

	void Fight();
	//용사가 몬스터를 때림
	bool HitMonster();
	//몬스터가 용사를 때림
	bool HitHero();

private:
	bool monster_state_;
	bool hero_state_;
};