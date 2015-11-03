#include <iostream>
#include "GameManager.h"
#include "PlaceManager.h"
#include "EntityManager.h"
#include "../Base/BaseGameWorldPlace.h"

using namespace std;
GameManager::GameManager() {

};

GameManager::~GameManager() {

};

void GameManager::Init() {
	place_manager_ = PlaceManager::GetInstance();
	entity_manager_ = EntityManager::GetInstance();
};

void GameManager::ShowMenu() {
	cout<<"����� ���� ~ The Adventure Of Hero ~"<<endl;
	
	for( int i = 1 ; i <= place_manager_->GetPlaceMapSize() ; i++ ) {
		place_manager_->GetPlaceByKey(i)->ShowPlaceName();
	}
};

void GameManager::SelectMenu() {
	int menu = 0;
	cin >> menu;

	switch(menu) {
		case PLACE_INN:
		case PLACE_DUNGEON:
		case PLACE_PUB:
			place_manager_->GoPlaceByKey(menu);
			break;
		default:
			cout<<"�ٽ� ����"<<endl;
	}
};
