#include <iostream>
#include "GamePlacePub.h"
#include "../Manager/EntityManager.h"

using namespace std;
GamePlacePub::GamePlacePub() {
	place_type_ = PLACE_PUB;
};

GamePlacePub::~GamePlacePub() {

};

void GamePlacePub::ShowPlaceName() {
	cout<<"�� ��!"<<endl;
};

void GamePlacePub::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	EntityManager* entity_manager = EntityManager::GetInstance();
	
}