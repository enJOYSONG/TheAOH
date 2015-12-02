#include <iostream>
#include "BattleManager.h"
#include "EntityManager.h"

using std::cout;

BattleManager::BattleManager() {
	monster_state_, hero_state_ = true;
};

void BattleManager::Fight() {
	if(ENTITY_MANAGER()->GetHeroHP() <= 0) {
		cout<<"����� HP�� �����մϴ�.\n";
	}
	else {
		cout<<"������ ���Խ��ϴ�!\n";
		ENTITY_MANAGER()->SetMonsterMap(ENTITY_MANAGER()->GetHeroLevel());
		ENTITY_MANAGER()->SetFirstMonsterRandom();
		
		//PT�� ���� ���������� ����?!
		//�ϴ� ��� ���������� �س���.
		while(true) {
			if(ENTITY_MANAGER()->GetHeroLevel() >= ENTITY_MANAGER()->GetMonsterLevel()) {
				monster_state_ = HitMonster();
			}
			else {
				hero_state_ = HitHero();
			}
			if(true == hero_state_) {
				monster_state_ = HitMonster();
			}
			else {
				cout<<"��� �й�...\n";
				break;
			}

			if(true == monster_state_) {
				hero_state_ = HitHero();
			}
			else {
				cout<<"��� �¸�!\n";
				break;
			}
		}
	}
};

bool BattleManager::HitMonster() {
	cout<<"��簡 "<<ENTITY_MANAGER()->GetMonsterName()<<"��(��) �ƴ�!\n";
	int hero_attack = ENTITY_MANAGER()->GetHeroAttack();
	ENTITY_MANAGER()->DecreaseMonsterHp(hero_attack);
	cout<<"������ HP : "<<ENTITY_MANAGER()->GetMonsterHP()<<"\n";
	return ENTITY_MANAGER()->CheckMonsterState();
};

bool BattleManager::HitHero() {
	cout<<ENTITY_MANAGER()->GetMonsterName()<<"��(��) ��縦 �ƴ�!\n";
	int monster_attack = ENTITY_MANAGER()->GetMonsterAttack();
	ENTITY_MANAGER()->DecreaseHeroHp(monster_attack);
	cout<<"����� HP : "<<ENTITY_MANAGER()->GetHeroHP()<<"\n";
	return ENTITY_MANAGER()->CheckHeroState();
};