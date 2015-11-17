//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceInn : public IBaseGameWorldPlace {
public :
	GamePlaceInn();
	GamePlaceInn(int pay, int recovery_trend_sp=0);
	virtual ~GamePlaceInn();
	inline PLACE_TYPE getType() { return place_type_; }
	virtual void ShowPlaceName();
	virtual void EnterPlace();
	void SelectMenu();
	void HealSP();

private:
	PLACE_TYPE place_type_;

	//sp 회복하는데 드는 돈
	int pay_;
	//sp 회복량
	//기본 20(임시)
	int recovery_trend_sp_;

};
