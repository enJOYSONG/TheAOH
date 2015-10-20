//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceDunjeon : public IBaseGameWorldPlace {
public :
	GamePlaceDunjeon();
	virtual ~GamePlaceDunjeon();
	inline PLACE_TYPE getType() { return place_type_ ; }
	virtual void ShowPlaceName();

private:
	PLACE_TYPE place_type_;
};
