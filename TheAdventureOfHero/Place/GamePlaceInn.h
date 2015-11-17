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

	//sp ȸ���ϴµ� ��� ��
	int pay_;
	//sp ȸ����
	//�⺻ 20(�ӽ�)
	int recovery_trend_sp_;

};
