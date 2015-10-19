#include "PlaceManager.h"
#include "../Base/BaseGameWorldPlace.h"
#include "../Place/GamePlaceInn.h"
#include "../Place/GamePlacePub.h"
#include "../Place/GamePlaceDunjeon.h"

using namespace std;
void PlaceManager::Init() {
	placeInn_ = new GamePlaceInn();
	place_map_.insert(map< int, IBaseGameWorldPlace* >::value_type(1, placeInn_));

	placePub_ = new GamePlacePub();
	place_map_.insert(map< int, IBaseGameWorldPlace* >::value_type(2, placePub_));

	placeDunjeon_ = new GamePlaceDunjeon();
	place_map_.insert(map< int, IBaseGameWorldPlace* >::value_type(3, placeDunjeon_));
};