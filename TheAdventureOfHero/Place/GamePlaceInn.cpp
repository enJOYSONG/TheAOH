#include <iostream>
#include "GamePlaceInn.h"
#include "../Manager/EntityManager.h"
using namespace std;

GamePlaceInn::GamePlaceInn() {
	place_type_ = PLACE_INN;
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
			HealSP();
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

void GamePlaceInn::HealSP() {
	cout<<"SP ȸ��"<<endl;
	EnterPlace();
};