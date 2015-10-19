//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlacePub : public IBaseGameWorldPlace {
public :
	GamePlacePub();
	virtual ~GamePlacePub();
	inline PlaceType getType() { return place_type_ ; }
private:
	PlaceType place_type_;
};
