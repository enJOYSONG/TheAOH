#pragma once

// Entity Manager!
// Have Hero Object
// Create Monster Object by Hero's level
class AliveObjectHero;
class AliveObjectMonster;
class EntityManager {
public:
	inline static EntityManager* GetInstance() {
		if (NULL == sEntityManager) {
			sEntityManager = new EntityManager();
			sEntityManager->Init();
		}

		return sEntityManager;
	};

	inline static void FreeInstance() {
		if (NULL != sEntityManager) {
			delete sEntityManager; 
			sEntityManager = NULL;
		}
	};

	const char* GetHeroName();

	//Hero stat getter setter
	int GetHeroHPAll();
	void SetHeroHPAll(int HP_All);

	int GetHeroSPAll();
	void SetHeroSPAll(int SP_All);

	int GetHeroHP();
	void SetHeroHP(int HP);

	int GetHeroSP();
	void SetHeroSP(int SP);

	int GetHeroAttack();
	void SetHeroAttack(int ATK);

	int GetHeroDeffense();
	void SetHeroDeffense(int DEF);

	int GetHeroLevel();
	void SetHeroLevel(int LEV);

	int GetHeroGold();
	void SetHeroGold(int GOLD);

	//Monster stat getter setter
	int GetMonsterHP();
	void SetMonsterHP(int HP);
	
	int GetMonsterAttack();
	void SetMonsterAttack(int ATK);

	int GetMonsterDeffense();
	void SetMonsterDeffense(int DEF);

	//check state
	bool CheckHeroState();
	bool CheckMonsterState();

private:
	static EntityManager* sEntityManager;
	EntityManager(){};
	~EntityManager(){};
	void Init();
	//�� ������ ĳ���͸� �����Ҷ����� �ٲ�
	//�Ŀ� object hero map ���� ����
	AliveObjectHero* first_hero_;
	//�� ������ ���Ͱ� �����Ҷ����� �ٲ�
	//�Ŀ� object monster map ���� ����
	AliveObjectMonster* first_monster_;
	
};