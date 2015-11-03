#pragma once

// Place Manager!
// Manage Place Map
#include <map>

class IBaseGameWorldPlace;
class EntityManager;
class PlaceManager {
public:
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
	void GoPlaceByKey(int place_type);

private:
	static PlaceManager* sPlaceManager;
	PlaceManager(){};
	~PlaceManager(){};
	void Init();
	
	std::map<int, IBaseGameWorldPlace*> place_map_;
};