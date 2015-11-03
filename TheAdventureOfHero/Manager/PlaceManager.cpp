#include <iostream>

#include "PlaceManager.h"
#include "EntityManager.h"
#include "../Base/BaseGameWorldPlace.h"
#include "../Place/GamePlaceInn.h"
#include "../Place/GamePlacePub.h"
#include "../Place/GamePlaceDunjeon.h"

using namespace std;

PlaceManager* PlaceManager::sPlaceManager = NULL;

void PlaceManager::Init() {
	IBaseGameWorldPlace* placeInn_ = new GamePlaceInn();
	place_map_[PLACE_INN] = placeInn_;

	IBaseGameWorldPlace* placeDunjeon_ = new GamePlaceDunjeon();
	place_map_[PLACE_DUNGEON] = placeDunjeon_;

	IBaseGameWorldPlace* placePub_ = new GamePlacePub();
	place_map_[PLACE_PUB] = placePub_;
};

IBaseGameWorldPlace* PlaceManager::GetPlaceByKey(int place_type) {
	switch(place_type) {
		case NONE_PLACE:
			return NULL;
			break;
		case PLACE_INN:
		case PLACE_DUNGEON:
		case PLACE_PUB:
			return place_map_.at(place_type);
			break;
		default:
			break;
	};
};

void PlaceManager::GoPlaceByKey(int place_type) {
	IBaseGameWorldPlace* place = place_map_[place_type];
	place->EnterPlace();
};
