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
	cout<<"SP 회복"<<endl;
	EnterPlace();
};