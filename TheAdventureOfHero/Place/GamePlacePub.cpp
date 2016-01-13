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
	cout<<"�� ��!"<<endl;
};

bool GamePlacePub::SelectMenu() {
	int menu;
	bool isMovePlace = false;

	while(true) {
		cout<<"1. HP ȸ��"<<endl;
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

bool GamePlacePub::EnterPlace() {
	cout << "~~~~~~~~����~~~~~~~~" <<endl;
	return SelectMenu();
}

void GamePlacePub::SpecificActionByPlace() {
	int hero_gold = ENTITY_MANAGER()->GetHeroGold();
	int hero_hp = ENTITY_MANAGER()->GetHeroHP();
	//ȸ���� hp��
	int hero_hp_all = ENTITY_MANAGER()->GetHeroHPAll();

	cout<<ENTITY_MANAGER()->GetHeroName()<<endl;
	cout<<"Gold : "<<hero_gold<<endl;
	cout<<"HP : "<<hero_hp<<endl;
	
	if( hero_gold > pay_ ) {
		//HP ȸ��
		ENTITY_MANAGER()->SetHeroHP(hero_hp_all);
		//�������
		ENTITY_MANAGER()->SetHeroGold(hero_gold - pay_);
		cout<<"HP ȸ��"<<endl;

		cout<<"Gold : "<<ENTITY_MANAGER()->GetHeroGold()<<endl;
		cout<<"HP : "<<ENTITY_MANAGER()->GetHeroHP()<<endl;
	}
	else {
		cout<<"��尡 �����մϴ�."<<endl;
	}
};

MovePlaceObject* GamePlacePub::MoveOtherPlace() {
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