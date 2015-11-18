#include <iostream>
#include "GamePlacePub.h"
#include "../Manager/EntityManager.h"
using namespace std;

GamePlacePub::GamePlacePub() {
	place_type_ = PLACE_PUB;
	pay_ = 5;
	recovery_trend_hp_ = 20;
};

GamePlacePub::GamePlacePub(int pay, int recovery_trend_hp) {
	place_type_ = PLACE_INN;
	pay_ = pay;
	recovery_trend_hp_ = recovery_trend_hp;
};

GamePlacePub::~GamePlacePub() {

};

void GamePlacePub::ShowPlaceName() {
	cout<<"주 점!"<<endl;
};

void GamePlacePub::SelectMenu() {
	int menu;
	cout<<"1. HP 회복"<<endl;
	cout<<"2. 나가기"<<endl;
	
	cin>>menu;

	switch(menu) {
		case 1:
			HealHP();
			break;
		case 2:
			break;
		default:
			cout<<"다시 선택"<<endl;
			EnterPlace();
			break;
	}
};

void GamePlacePub::EnterPlace() {
	cout << "~~~~~~~~주점~~~~~~~~" <<endl;
	SelectMenu();
}

void GamePlacePub::HealHP() {
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
		cout<<"SP : "<<ENTITY_MANAGER()->GetHeroHP()<<endl;
		EnterPlace();
	}
	else {
		cout<<"골드가 부족합니다."<<endl;
	}
};