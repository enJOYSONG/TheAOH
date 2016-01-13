#include <iostream>
#include "GamePlaceDunjeon.h"
#include "../Manager/BattleManager.h"

using namespace std;

GamePlaceDunjeon::GamePlaceDunjeon() {
	place_type_ = PLACE_DUNGEON;
	place_map_ = new std::map<PLACE_TYPE,int>;
};

GamePlaceDunjeon::~GamePlaceDunjeon() {

};

void GamePlaceDunjeon::ShowPlaceName() {
	cout<<"던 전!"<<endl;
};

bool GamePlaceDunjeon::EnterPlace() {
	cout << "~~~~~~~~던전~~~~~~~~" <<endl;
	SpecificActionByPlace();
	return false;
};

void GamePlaceDunjeon::SpecificActionByPlace() {
	BattleManager battle_manager;
	battle_manager.Fight();
};

MovePlaceObject* GamePlaceDunjeon::MoveOtherPlace() {
	cout << "이동할 장소를 선택하세요." << endl;
	map< PLACE_TYPE, int >::iterator Iter_Pos;
	int menu = 0;
	for( Iter_Pos = place_map_->begin(); Iter_Pos != place_map_->end(); ++Iter_Pos)
	{
		switch(Iter_Pos->first) {
		case NONE_PLACE:
			break;
		case PLACE_INN:
			cout << "여관, 필요 SP : " << Iter_Pos->second <<endl;
			cout << "이동을 원한다면 " << PLACE_INN <<"을(를) 누르세요."<<endl;
			break;
		case PLACE_DUNGEON:
			cout << "던전, 필요 SP : " << Iter_Pos->second <<endl;
			cout << "이동을 원한다면 " << PLACE_DUNGEON <<"을(를) 누르세요."<<endl;
			break;
		case PLACE_PUB:
			cout << "주점, 필요 SP : " << Iter_Pos->second <<endl;
			cout << "이동을 원한다면 " << PLACE_PUB <<"을(를) 누르세요."<<endl;
			break;
		default:
			break;
		}
	}

	cin>>menu;

	switch(menu) {
	case PLACE_INN:
	case PLACE_DUNGEON:
	case PLACE_PUB:
		break;
	default:
		cout<<"다시 입력하세요."<<endl;
		MoveOtherPlace();
		break;
	}

	return new MovePlaceObject((PLACE_TYPE)menu, place_map_->at((PLACE_TYPE)menu));
}