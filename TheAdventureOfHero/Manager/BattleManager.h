#pragma once

// Battle Manager!

class EntityManager;
class BattleManager {
public:
	BattleManager();
	~BattleManager(){};

	void Fight();
	//��簡 ���͸� ����
	bool HitMonster();
	//���Ͱ� ��縦 ����
	bool HitHero();

private:
	bool monster_state_;
	bool hero_state_;
};