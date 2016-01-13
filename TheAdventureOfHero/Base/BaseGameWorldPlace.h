#pragma once
#include <map>
//GamePlace interface
//set place type by enum
enum PLACE_TYPE {
	NONE_PLACE = 0,
	PLACE_INN = 1,
	PLACE_DUNGEON = 2,
	PLACE_PUB = 3,
};

class MovePlaceObject;
class IBaseGameWorldPlace {
public:
	virtual PLACE_TYPE getType()=0;
	virtual void ShowPlaceName()=0;
	virtual bool EnterPlace()=0;
	virtual void SpecificActionByPlace()=0;
	virtual MovePlaceObject* MoveOtherPlace()=0;
	virtual std::map<PLACE_TYPE,int>* GetPlaceMap()=0;
};

class MovePlaceObject {
public:
	MovePlaceObject(PLACE_TYPE place, int distance) {
		place_ = place;
		distance_ = distance;
	};

	~MovePlaceObject() {
	}

	int GetDistance() { return distance_; };
	void SetDistance(int distance) { distance_ = distance; };

	PLACE_TYPE GetPlace() { return place_; };
	void SetPlace(PLACE_TYPE place) { place_ = place; };

private:
	int distance_;
	PLACE_TYPE place_;
};