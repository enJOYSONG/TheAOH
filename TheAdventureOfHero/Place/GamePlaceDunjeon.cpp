#include <iostream>
#include "GamePlaceDunjeon.h"
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
};

bool GamePlaceDunjeon::Fight() {
	return true;
};