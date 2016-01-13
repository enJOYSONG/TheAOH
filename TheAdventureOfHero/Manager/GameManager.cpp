#include <iostream>
#include "GameManager.h"
#include "PlaceManager.h"
#include "EntityManager.h"
#include "../Base/BaseGameWorldPlace.h"
using namespace std;

GameManager::GameManager() {

};

GameManager::~GameManager() {
	place_manager_->DeInit();
	place_manager_ = NULL;

	entity_manager_->DeInit();
	entity_manager_ = NULL;
};

void GameManager::Init() {
	place_manager_ = PlaceManager::GetInstance();
	entity_manager_ = EntityManager::GetInstance();
};

void GameManager::ShowMenu() {
	cout<<"용사의 모험 ~ The Adventure Of Hero ~"<<endl;
	
	for( int i = 1 ; i <= place_manager_->GetPlaceMapSize() ; i++ ) {
		place_manager_->GetPlaceByKey(i)->ShowPlaceName();
	}
};

void GameManager::SelectMenu() {
	int menu = 0;
	bool isMove = false;

	while(true) {
		if(isMove)
			menu = place_manager_->GetMovePlace()->GetPlace();
		
		else 
			cin >> menu;

		switch(menu) {
			case PLACE_INN:
			case PLACE_DUNGEON:
			case PLACE_PUB:
				isMove = place_manager_->GoPlaceByKey(menu);
				break;
			default:
				cout<<"다시 선택"<<endl;
				break;
		}
		if(!isMove)
			break;
	}
};
