#pragma once
//GamePlace interface
//set place type by enum
enum PLACE_TYPE {
	NONE_PLACE = 0,
	PLACE_INN = 1,
	PLACE_DUNGEON = 2,
	PLACE_PUB = 3,
};

class IBaseGameWorldPlace {
public:
	virtual PLACE_TYPE getType()=0;
	virtual void ShowPlaceName()=0;
	virtual void EnterPlace()=0;
	virtual void SpecificActionByPlace()=0;
};
