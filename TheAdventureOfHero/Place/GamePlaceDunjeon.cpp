#include <iostream>
#include "GamePlaceDunjeon.h"
using namespace std;

GamePlaceDunjeon::GamePlaceDunjeon() {
	place_type_ = PLACE_DUNGEON;
};

GamePlaceDunjeon::~GamePlaceDunjeon() {

};

void GamePlaceDunjeon::ShowPlaceName() {
	cout<<"´ø Àü!"<<endl;
};