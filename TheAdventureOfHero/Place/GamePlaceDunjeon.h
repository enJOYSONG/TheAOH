//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceDunjeon : public IBaseGameWorldPlace {
public :
	GamePlaceDunjeon();
	virtual ~GamePlaceDunjeon();
	inline PlaceType getType() { return place_type_ ; }
private:
	PlaceType place_type_;
};
