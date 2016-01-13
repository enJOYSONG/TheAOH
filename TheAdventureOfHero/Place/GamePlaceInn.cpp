#include <iostream>
#include "GamePlaceInn.h"
#include "../Manager/EntityManager.h"
using namespace std;

GamePlaceInn::GamePlaceInn() {
	place_type_ = PLACE_INN;
	pay_ = 10;
	recovery_trend_sp_ = 20;
	place_map_ = new std::map<PLACE_TYPE,int>;
};

GamePlaceInn::GamePlaceInn(int pay, int recovery_trend_sp) {
	place_type_ = PLACE_INN;
	pay_ = pay;
	recovery_trend_sp_ = recovery_trend_sp;
	place_map_ = new std::map<PLACE_TYPE,int>;
};

GamePlaceInn::~GamePlaceInn() {

};

void GamePlaceInn::ShowPlaceName() {
	cout<<"여 관!"<<endl;
};

bool GamePlaceInn::SelectMenu() {
	int menu;
	bool isMovePlace = false;
	while(true) {
		cout<<"1. SP 회복"<<endl;
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

bool GamePlaceInn::EnterPlace() {
	cout << "~~~~~~~~여관~~~~~~~~" <<endl;
	return SelectMenu();
	
};

void GamePlaceInn::SpecificActionByPlace() {
	int hero_gold = ENTITY_MANAGER()->GetHeroGold();
	int hero_sp = EntityManager::GetInstance()->GetHeroSP();
	//회복할 sp양
	int hero_sp_all = EntityManager::GetInstance()->GetHeroSPAll();

	cout<<EntityManager::GetInstance()->GetHeroName()<<endl;
	cout<<"Gold : "<<hero_gold<<endl;
	cout<<"SP : "<<hero_sp<<endl;
	
	if( hero_gold > pay_ ) {
		//SP 회복
		EntityManager::GetInstance()->SetHeroSP(hero_sp_all);
		//골드차감
		EntityManager::GetInstance()->SetHeroGold(hero_gold - pay_);
		cout<<"SP 회복"<<endl;

		cout<<"Gold : "<<EntityManager::GetInstance()->GetHeroGold()<<endl;
		cout<<"SP : "<<EntityManager::GetInstance()->GetHeroSP()<<endl;
	}
	else {
		cout<<"골드가 부족합니다."<<endl;
	}
};

MovePlaceObject* GamePlaceInn::MoveOtherPlace() {
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