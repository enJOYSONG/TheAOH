//GamePlace Inn
#include "../Base/BaseGameWorldPlace.h"

class GamePlaceInn : public IBaseGameWorldPlace {
public :
	GamePlaceInn();
	GamePlaceInn(int pay, int recovery_trend_sp=0);
	virtual ~GamePlaceInn();
	inline PLACE_TYPE getType() { return place_type_; }
	virtual void ShowPlaceName();
	virtual bool EnterPlace();
	bool SelectMenu();
	virtual void SpecificActionByPlace();
	virtual MovePlaceObject* MoveOtherPlace();
	virtual std::map<PLACE_TYPE,int>* GetPlaceMap() { return place_map_; }

private:
	PLACE_TYPE place_type_;

	//sp ȸ���ϴµ� ��� ��
	int pay_;
	//sp ȸ����
	//�⺻ 20(�ӽ�)
	int recovery_trend_sp_;
	std::map<PLACE_TYPE,int>* place_map_;


};
