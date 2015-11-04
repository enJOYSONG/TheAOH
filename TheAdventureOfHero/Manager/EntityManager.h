#pragma once

// Entity Manager!
// Have Hero Object
// Create Monster Object by Hero's level
class AliveObjectHero;
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
	
private:
	static EntityManager* sEntityManager;
	EntityManager(){};
	~EntityManager(){};
	void Init();
	//이 변수는 캐릭터를 선택할때마다 바뀜
	//후에 object hero map 만들 예정
	AliveObjectHero* first_hero_;
	
};