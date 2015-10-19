//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceInn : public IBaseGameWorldPlace {
public :
	GamePlaceInn();
	virtual ~GamePlaceInn();
	inline PlaceType getType() { return place_type_; }
private:
	PlaceType place_type_;
};
