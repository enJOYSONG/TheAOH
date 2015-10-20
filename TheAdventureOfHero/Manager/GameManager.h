#pragma once

//GameManager
//Manage place and entity
class PlaceManager;
class EntityManager;
class GameManager {
public:
	GameManager();
	~GameManager();
	void Init();

	void ShowAndSelectMenu();

private:
	PlaceManager* place_manager_;
	EntityManager* entity_manager_;
};