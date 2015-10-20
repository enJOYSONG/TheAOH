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

void GameManager::ShowAndSelectMenu() {
	cout<<"용사의 모험 ~ The Adventure Of Hero ~"<<endl;
	
	for( int i = 1 ; i <= place_manager_->GetPlaceMapSize() ; i++ ) {
		place_manager_->GetPlaceByKey(i)->ShowPlaceName();
	}

	place_manager_->GoPlaceInn();
};