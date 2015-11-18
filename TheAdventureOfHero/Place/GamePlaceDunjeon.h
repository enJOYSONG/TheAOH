//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceDunjeon : public IBaseGameWorldPlace {
public :
	GamePlaceDunjeon();
	virtual ~GamePlaceDunjeon();
	inline PLACE_TYPE getType() { return place_type_ ; }
	virtual void ShowPlaceName();
	virtual void EnterPlace();

	bool Fight();
private:
	PLACE_TYPE place_type_;
};
