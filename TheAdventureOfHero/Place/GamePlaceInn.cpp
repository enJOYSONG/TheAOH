#include <iostream>
#include "GamePlaceInn.h"
#include "../Manager/EntityManager.h"
using namespace std;

GamePlaceInn::GamePlaceInn() {
	place_type_ = PLACE_INN;
	pay_ = 10;
	recovery_trend_sp_ = 20;
};

GamePlaceInn::GamePlaceInn(int pay, int recovery_trend_sp) {
	place_type_ = PLACE_INN;
	pay_ = pay;
	recovery_trend_sp_ = recovery_trend_sp;
};

GamePlaceInn::~GamePlaceInn() {

};

void GamePlaceInn::ShowPlaceName() {
	cout<<"여 관!"<<endl;
};

void GamePlaceInn::SelectMenu() {
	int menu;
	cout<<"1. SP 회복"<<endl;
	cout<<"2. 나가기"<<endl;
	
	cin>>menu;

	switch(menu) {
		case 1:
			SpecificActionByPlace();
			break;
		case 2:
			break;
		default:
			cout<<"다시 선택"<<endl;
			EnterPlace();
			break;
	}
};

void GamePlaceInn::EnterPlace() {
	cout << "~~~~~~~~여관~~~~~~~~" <<endl;
	SelectMenu();
	
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
		EnterPlace();
	}
	else {
		cout<<"골드가 부족합니다."<<endl;
	}
};