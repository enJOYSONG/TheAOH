//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlacePub : public IBaseGameWorldPlace {
public :
	GamePlacePub();
	GamePlacePub(int pay, int recovery_trend_hp=0);
	virtual ~GamePlacePub();
	inline PLACE_TYPE getType() { return place_type_ ; }
	virtual void ShowPlaceName();
	virtual bool EnterPlace();
	bool SelectMenu();
	virtual void SpecificActionByPlace();
	virtual MovePlaceObject* MoveOtherPlace();
	virtual std::map<PLACE_TYPE,int>* GetPlaceMap() { return place_map_; }

private:
	PLACE_TYPE place_type_;

	//hp 회복하는데 드는 돈
	int pay_;
	//hp 회복량
	//기본 20(임시)
	int recovery_trend_hp_;
	std::map<PLACE_TYPE,int>* place_map_;
};
