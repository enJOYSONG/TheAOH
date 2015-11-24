#include <iostream>
#include "BattleManager.h"
#include "EntityManager.h"

using std::cout;

BattleManager::BattleManager() {
	monster_state_, hero_state_ = true;
};

void BattleManager::Fight() {
	if(ENTITY_MANAGER()->GetHeroHP() <= 0) {
		cout<<"용사의 HP가 부족합니다.\n";
	}
	else {
		cout<<"던전에 들어왔습니다!";
		ENTITY_MANAGER()->SetMonsterMap();
		ENTITY_MANAGER()->SetFirstMonsterRandom();
		
		//PT에 몬스터 레벨관련이 없다?!
		//일단 용사 선공격으로 해놓음.
		while(true) {
			if(true == hero_state_) {
				monster_state_ = HitMonster();
			}
			else {
				cout<<"용사 패배...\n";
				break;
			}

			if(true == monster_state_) {
				hero_state_ = HitHero();
			}
			else {
				cout<<"용사 승리!\n";
				break;
			}
		}
	}
};

bool BattleManager::HitMonster() {
	cout<<"용사가 몬스터를 쳤다!\n";
	int hero_attack = ENTITY_MANAGER()->GetHeroAttack();
	ENTITY_MANAGER()->DecreaseMonsterHp(hero_attack);
	cout<<"몬스터의 HP : "<<ENTITY_MANAGER()->GetMonsterHP()<<"\n";
	return ENTITY_MANAGER()->CheckMonsterState();
};

bool BattleManager::HitHero() {
	cout<<"몬스터가 용사를 쳤다!\n";
	int monster_attack = ENTITY_MANAGER()->GetMonsterAttack();
	ENTITY_MANAGER()->DecreaseHeroHp(monster_attack);
	cout<<"용사의 HP : "<<ENTITY_MANAGER()->GetHeroHP()<<"\n";
	return ENTITY_MANAGER()->CheckHeroState();
};