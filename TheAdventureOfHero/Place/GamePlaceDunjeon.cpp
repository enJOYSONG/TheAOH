#include <iostream>
#include "GamePlaceDunjeon.h"
#include "../Manager/EntityManager.h"

using namespace std;

GamePlaceDunjeon::GamePlaceDunjeon() {
	place_type_ = PLACE_DUNGEON;
};

GamePlaceDunjeon::~GamePlaceDunjeon() {

};

void GamePlaceDunjeon::ShowPlaceName() {
	cout<<"던 전!"<<endl;
};

void GamePlaceDunjeon::EnterPlace() {
	cout << "~~~~~~~~던전~~~~~~~~" <<endl;
	Fight();
};

bool GamePlaceDunjeon::Fight() {
	cout<<"던전에 들어왔습니다!"<<endl;
	return true;
};