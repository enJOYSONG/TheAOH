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
	cout<<"�� ��!"<<endl;
};

void GamePlacePub::SelectMenu() {
	int menu;
	cout<<"1. HP ȸ��"<<endl;
	cout<<"2. ������"<<endl;
	
	cin>>menu;

	switch(menu) {
		case 1:
			HealHP();
			break;
		case 2:
			break;
		default:
			cout<<"�ٽ� ����"<<endl;
			EnterPlace();
			break;
	}
};

void GamePlacePub::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	SelectMenu();
}

void GamePlacePub::HealHP() {
	int hero_gold = EntityManager::GetInstance()->GetHeroGold();
	int hero_hp = EntityManager::GetInstance()->GetHeroHP();
	//ȸ���� hp��
	int hero_hp_all = EntityManager::GetInstance()->GetHeroHPAll();

	cout<<EntityManager::GetInstance()->GetHeroName()<<endl;
	cout<<"Gold : "<<hero_gold<<endl;
	cout<<"HP : "<<hero_hp<<endl;
	
	if( hero_gold > pay_ ) {
		//HP ȸ��
		EntityManager::GetInstance()->SetHeroHP(hero_hp_all);
		//�������
		EntityManager::GetInstance()->SetHeroGold(hero_gold - pay_);
		cout<<"HP ȸ��"<<endl;

		cout<<"Gold : "<<EntityManager::GetInstance()->GetHeroGold()<<endl;
		cout<<"SP : "<<EntityManager::GetInstance()->GetHeroHP()<<endl;
		EnterPlace();
	}
	else {
		cout<<"��尡 �����մϴ�."<<endl;
	}
};