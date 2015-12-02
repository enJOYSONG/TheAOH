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
	SpecificActionByPlace();
};

void GamePlaceDunjeon::SpecificActionByPlace() {
	BattleManager battle_manager;
	battle_manager.Fight();
};