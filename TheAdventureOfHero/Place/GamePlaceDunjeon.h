//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class BattleManager;
class GamePlaceDunjeon : public IBaseGameWorldPlace {
public :
	GamePlaceDunjeon();
	virtual ~GamePlaceDunjeon();
	inline PLACE_TYPE getType() { return place_type_ ; }
	virtual void ShowPlaceName();
	virtual bool EnterPlace();
	virtual void SpecificActionByPlace();
	virtual MovePlaceObject* MoveOtherPlace();
	virtual std::map<PLACE_TYPE,int>* GetPlaceMap() { return place_map_; }

private:
	PLACE_TYPE place_type_;
	std::map<PLACE_TYPE,int>* place_map_;
};
