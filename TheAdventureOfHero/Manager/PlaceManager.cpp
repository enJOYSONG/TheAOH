#include "PlaceManager.h"
#include "../Base/BaseGameWorldPlace.h"
#include "../Place/GamePlaceInn.h"
#include "../Place/GamePlacePub.h"
#include "../Place/GamePlaceDunjeon.h"

void PlaceManager::Init() {
	placeInn_ = new GamePlaceInn();
	place_map_.insert(placeInn_);

	placePub_ = new GamePlacePub();
	place_map_.insert(placePub_);

	placeDunjeon_ = new GamePlaceDunjeon();
	place_map_.insert(placeDunjeon_);
};