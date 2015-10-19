#pragma once
//GamePlace interface
//set place type by enum
enum PlaceType {
	NONE_PLACE = 0,
	PLACE_INN = 1,
	PLACE_DUNGEON = 2,
	PLACE_PUB = 3,
};

class IBaseGameWorldPlace {
public:
	virtual PlaceType getType()=0;
};
