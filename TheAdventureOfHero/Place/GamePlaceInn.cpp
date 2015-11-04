#include <iostream>
#include "GamePlaceInn.h"
#include "../Manager/EntityManager.h"
using namespace std;

GamePlaceInn::GamePlaceInn() {
	place_type_ = PLACE_INN;
	pay_ = 10;
	recovery_trend_ = 20;
};

GamePlaceInn::GamePlaceInn(int pay, int recovery_trend) {
	place_type_ = PLACE_INN;
	pay_ = pay;
	recovery_trend_ = recovery_trend;
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
			HealSP();
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

void GamePlaceInn::HealSP() {
	EntityManager* entity_manager = EntityManager::GetInstance();
	int hero_gold = entity_manager->GetHeroGold();
	int hero_sp = entity_manager->GetHeroSP();

	cout<<entity_manager->GetHeroName()<<endl;
	cout<<"Gold : "<<hero_gold<<endl;
	cout<<"SP : "<<hero_sp<<endl;
	
	//현재 sp와 회복세를 더한값
	entity_manager->SetHeroSP(hero_sp + recovery_trend_);
	//골드차감
	entity_manager->SetHeroGold(hero_gold - pay_);
	cout<<"SP 회복"<<endl;

	cout<<"Gold : "<<entity_manager->GetHeroGold()<<endl;
	cout<<"SP : "<<entity_manager->GetHeroSP()<<endl;
	EnterPlace();
};