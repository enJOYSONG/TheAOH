//GamePlace interface
//set place type by enum
enum PlaceType {
	NONE_PLACE,
	PLACE_INN,
	PLACE_DUNGEON,
	PLACE_PUB
};

class IBaseGameWorldPlace {
protected:
	PlaceType place_type_;
};
