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

	/*place_map_[PLACE_INN]->GetPlaceMap().insert(std::pair<int, MovePlaceObject*>(0, new MovePlaceObject(2, PLACE_DUNGEON)));
	place_map_[PLACE_INN]->GetPlaceMap().insert(std::pair<int, MovePlaceObject*>(1, new MovePlaceObject(2, PLACE_PUB)));

	place_map_[PLACE_PUB]->GetPlaceMap().insert(std::pair<int, MovePlaceObject*>(0, new MovePlaceObject(2, PLACE_INN)));
	place_map_[PLACE_PUB]->GetPlaceMap().insert(std::pair<int, MovePlaceObject*>(1, new MovePlaceObject(3, PLACE_DUNGEON)));

	place_map_[PLACE_DUNGEON]->GetPlaceMap().insert(std::pair<int, MovePlaceObject*>(0, new MovePlaceObject(2,PLACE_INN)));
	place_map_[PLACE_DUNGEON]->GetPlaceMap().insert(std::pair<int, MovePlaceObject*>(1, new MovePlaceObject(3, PLACE_PUB)));*/

	place_map_[PLACE_INN]->GetPlaceMap()->insert(std::pair<PLACE_TYPE, int>(PLACE_DUNGEON, 2));
	place_map_[PLACE_INN]->GetPlaceMap()->insert(std::pair<PLACE_TYPE, int>(PLACE_PUB, 2));

	place_map_[PLACE_PUB]->GetPlaceMap()->insert(std::pair<PLACE_TYPE, int>(PLACE_INN, 2));
	place_map_[PLACE_PUB]->GetPlaceMap()->insert(std::pair<PLACE_TYPE, int>(PLACE_DUNGEON, 3));

	place_map_[PLACE_DUNGEON]->GetPlaceMap()->insert(std::pair<PLACE_TYPE, int>(PLACE_INN, 2));
	place_map_[PLACE_DUNGEON]->GetPlaceMap()->insert(std::pair<PLACE_TYPE, int>(PLACE_PUB, 3));

	

};

void PlaceManager::DeInit() {
	map< int, IBaseGameWorldPlace* >::iterator Iter_Pos;
	for( Iter_Pos = place_map_.begin(); Iter_Pos != place_map_.end(); ++Iter_Pos)
	{
		delete Iter_Pos->second;
	}

	delete sPlaceManager;
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

bool PlaceManager::GoPlaceByKey(int place_type) {
	IBaseGameWorldPlace* place = place_map_[place_type];
	bool isMovePlace = place->EnterPlace();
	if(isMovePlace) {
		move_place = place->MoveOtherPlace();
		ENTITY_MANAGER()->SetHeroSP(ENTITY_MANAGER()->GetHeroSP() - move_place->GetDistance());
	}
	return isMovePlace;
};
