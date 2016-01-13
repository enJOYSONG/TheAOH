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
	cout<<"�� ��!"<<endl;
};

bool GamePlaceInn::SelectMenu() {
	int menu;
	bool isMovePlace = false;
	while(true) {
		cout<<"1. SP ȸ��"<<endl;
		cout<<"2. ��� �̵�"<<endl;
		cout<<"3. ������"<<endl;

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
			cout<<"�ٽ� ����"<<endl;
		}
		if(menu != 1)
			break;
	}
	return isMovePlace;
};

bool GamePlaceInn::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	return SelectMenu();
	
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
	}
	else {
		cout<<"��尡 �����մϴ�."<<endl;
	}
};

MovePlaceObject* GamePlaceInn::MoveOtherPlace() {
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