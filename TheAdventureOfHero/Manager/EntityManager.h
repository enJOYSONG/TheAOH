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
private:
	static EntityManager* sEntityManager;
	EntityManager(){};
	~EntityManager(){};
	void Init();

	AliveObjectHero* first_hero_;
};