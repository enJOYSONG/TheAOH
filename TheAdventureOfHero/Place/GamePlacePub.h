//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlacePub : public IBaseGameWorldPlace {
public :
	GamePlacePub();
	virtual ~GamePlacePub();
	inline PLACE_TYPE getType() { return place_type_ ; }
	virtual void ShowPlaceName();
	virtual void EnterPlace();

private:
	PLACE_TYPE place_type_;
};
