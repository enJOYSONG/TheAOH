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
	cout<<"�� ��!"<<endl;
};

bool GamePlaceDunjeon::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	SpecificActionByPlace();
	return false;
};

void GamePlaceDunjeon::SpecificActionByPlace() {
	BattleManager battle_manager;
	battle_manager.Fight();
};

MovePlaceObject* GamePlaceDunjeon::MoveOtherPlace() {
	cout << "�̵��� ��Ҹ� �����ϼ���." << endl;
	map< PLACE_TYPE, int >::iterator Iter_Pos;
	int menu = 0;
	for( Iter_Pos = place_map_->begin(); Iter_Pos != place_map_->end(); ++Iter_Pos)
	{
		switch(Iter_Pos->first) {
		case NONE_PLACE:
			break;
		case PLACE_INN:
			cout << "����, �ʿ� SP : " << Iter_Pos->second <<endl;
			cout << "�̵��� ���Ѵٸ� " << PLACE_INN <<"��(��) ��������."<<endl;
			break;
		case PLACE_DUNGEON:
			cout << "����, �ʿ� SP : " << Iter_Pos->second <<endl;
			cout << "�̵��� ���Ѵٸ� " << PLACE_DUNGEON <<"��(��) ��������."<<endl;
			break;
		case PLACE_PUB:
			cout << "����, �ʿ� SP : " << Iter_Pos->second <<endl;
			cout << "�̵��� ���Ѵٸ� " << PLACE_PUB <<"��(��) ��������."<<endl;
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
		cout<<"�ٽ� �Է��ϼ���."<<endl;
		MoveOtherPlace();
		break;
	}

	return new MovePlaceObject((PLACE_TYPE)menu, place_map_->at((PLACE_TYPE)menu));
}