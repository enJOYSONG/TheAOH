#include <iostream>
#include "GamePlacePub.h"
#include "../Manager/EntityManager.h"
using namespace std;

GamePlacePub::GamePlacePub() {
	place_type_ = PLACE_PUB;
	pay_ = 5;
	recovery_trend_hp_ = 20;
	place_map_ = new std::map<PLACE_TYPE,int>;
};

GamePlacePub::GamePlacePub(int pay, int recovery_trend_hp) {
	place_type_ = PLACE_INN;
	pay_ = pay;
	recovery_trend_hp_ = recovery_trend_hp;
	place_map_ = new std::map<PLACE_TYPE,int>;
};

GamePlacePub::~GamePlacePub() {

};

void GamePlacePub::ShowPlaceName() {
	cout<<"주 점!"<<endl;
};

bool GamePlacePub::SelectMenu() {
	int menu;
	bool isMovePlace = false;

	while(true) {
		cout<<"1. HP 회복"<<endl;
		cout<<"2. 장소 이동"<<endl;
		cout<<"3. 나가기"<<endl;
	
		cin>>menu;

		switch(menu) {
			case 1:
				SpecificActionByPlace();
				break;
			case 2:
				isMovePlace = true;
				break;
			case 3:
				break;
			default:
				cout<<"다시 선택"<<endl;
		}
		if(menu != 1)
			break;
	}
	
	return isMovePlace;
};

bool GamePlacePub::EnterPlace() {
	cout << "~~~~~~~~주점~~~~~~~~" <<endl;
	return SelectMenu();
}

void GamePlacePub::SpecificActionByPlace() {
	int hero_gold = ENTITY_MANAGER()->GetHeroGold();
	int hero_hp = ENTITY_MANAGER()->GetHeroHP();
	//회복할 hp양
	int hero_hp_all = ENTITY_MANAGER()->GetHeroHPAll();

	cout<<ENTITY_MANAGER()->GetHeroName()<<endl;
	cout<<"Gold : "<<hero_gold<<endl;
	cout<<"HP : "<<hero_hp<<endl;
	
	if( hero_gold > pay_ ) {
		//HP 회복
		ENTITY_MANAGER()->SetHeroHP(hero_hp_all);
		//골드차감
		ENTITY_MANAGER()->SetHeroGold(hero_gold - pay_);
		cout<<"HP 회복"<<endl;

		cout<<"Gold : "<<ENTITY_MANAGER()->GetHeroGold()<<endl;
		cout<<"HP : "<<ENTITY_MANAGER()->GetHeroHP()<<endl;
	}
	else {
		cout<<"골드가 부족합니다."<<endl;
	}
};

MovePlaceObject* GamePlacePub::MoveOtherPlace() {
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