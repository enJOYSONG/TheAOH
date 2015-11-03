//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceInn : public IBaseGameWorldPlace {
public :
	GamePlaceInn();
	virtual ~GamePlaceInn();
	inline PLACE_TYPE getType() { return place_type_; }
	virtual void ShowPlaceName();
	virtual void EnterPlace();
	void SelectMenu();
	void HealSP();

private:
	PLACE_TYPE place_type_;
};
