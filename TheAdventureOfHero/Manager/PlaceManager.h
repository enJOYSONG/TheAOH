#pragma once

// Place Manager!
// Manage Place Map
#include <map>

class IBaseGameWorldPlace;
class EntityManager;
class MovePlaceObject;
class PlaceManager {
public:
	PlaceManager(){};
	~PlaceManager(){};
	void Init();
	void DeInit();

//sington object - place manager
	inline static PlaceManager* GetInstance() {
		if (NULL == sPlaceManager) {
			sPlaceManager = new PlaceManager();
			sPlaceManager->Init();
		}

		return sPlaceManager;
	};

	inline static void FreeInstance() {
		if (NULL != sPlaceManager) {
			delete sPlaceManager; 
			sPlaceManager = NULL;
		}
	};
	
	inline int GetPlaceMapSize() {
		return place_map_.size();
	};
	
	//return place by place type enum
	IBaseGameWorldPlace* GetPlaceByKey(int place_type);
	bool GoPlaceByKey(int place_type);
	MovePlaceObject* GetMovePlace() { return move_place; };

private:
	static PlaceManager* sPlaceManager;
	std::map<int, IBaseGameWorldPlace*> place_map_;
	MovePlaceObject* move_place;
};