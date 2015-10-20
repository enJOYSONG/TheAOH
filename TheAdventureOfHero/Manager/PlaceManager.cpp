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
	place_map_.insert(map< int, IBaseGameWorldPlace* >::value_type(1, placeInn_));

	IBaseGameWorldPlace* placeDunjeon_ = new GamePlaceDunjeon();
	place_map_.insert(map< int, IBaseGameWorldPlace* >::value_type(2, placeDunjeon_));

	IBaseGameWorldPlace* placePub_ = new GamePlacePub();
	place_map_.insert(map< int, IBaseGameWorldPlace* >::value_type(3, placePub_));
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
