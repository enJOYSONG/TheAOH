#include <iostream>
#include "GamePlaceDunjeon.h"
#include "../Manager/BattleManager.h"

using namespace std;

GamePlaceDunjeon::GamePlaceDunjeon() {
	place_type_ = PLACE_DUNGEON;
};

GamePlaceDunjeon::~GamePlaceDunjeon() {

};

void GamePlaceDunjeon::ShowPlaceName() {
	cout<<"�� ��!"<<endl;
};

void GamePlaceDunjeon::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	Fight();
};

bool GamePlaceDunjeon::Fight() {
	BattleManager battle_manager;
	battle_manager.Fight();
	return true;
};