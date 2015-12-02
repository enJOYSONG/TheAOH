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
	cout<<"�� ��!"<<endl;
};

void GamePlaceInn::SelectMenu() {
	int menu;
	cout<<"1. SP ȸ��"<<endl;
	cout<<"2. ������"<<endl;
	
	cin>>menu;

	switch(menu) {
		case 1:
			SpecificActionByPlace();
			break;
		case 2:
			break;
		default:
			cout<<"�ٽ� ����"<<endl;
			EnterPlace();
			break;
	}
};

void GamePlaceInn::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	SelectMenu();
	
};

void GamePlaceInn::SpecificActionByPlace() {
	int hero_gold = ENTITY_MANAGER()->GetHeroGold();
	int hero_sp = EntityManager::GetInstance()->GetHeroSP();
	//ȸ���� sp��
	int hero_sp_all = EntityManager::GetInstance()->GetHeroSPAll();

	cout<<EntityManager::GetInstance()->GetHeroName()<<endl;
	cout<<"Gold : "<<hero_gold<<endl;
	cout<<"SP : "<<hero_sp<<endl;
	
	if( hero_gold > pay_ ) {
		//SP ȸ��
		EntityManager::GetInstance()->SetHeroSP(hero_sp_all);
		//�������
		EntityManager::GetInstance()->SetHeroGold(hero_gold - pay_);
		cout<<"SP ȸ��"<<endl;

		cout<<"Gold : "<<EntityManager::GetInstance()->GetHeroGold()<<endl;
		cout<<"SP : "<<EntityManager::GetInstance()->GetHeroSP()<<endl;
		EnterPlace();
	}
	else {
		cout<<"��尡 �����մϴ�."<<endl;
	}
};