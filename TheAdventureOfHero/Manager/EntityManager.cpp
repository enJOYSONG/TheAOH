#include <iostream>
#include "EntityManager.h"
#include "../Hero/AliveObjectHero.h"
#include "../Monster/AliveObjectMonster.h"

using namespace std;

EntityManager* EntityManager::sEntityManager = NULL;

void EntityManager::Init() {
	first_hero_ = new AliveObjectHero;
	first_monster_ = NULL;
};

void EntityManager::DeInit() {
	delete first_hero_;
	if(first_monster_ != NULL) 
		delete first_monster_;

	map< int, AliveObjectMonster* >::iterator Iter_Pos;
	for( Iter_Pos = monster_map_.begin(); Iter_Pos != monster_map_.end(); ++Iter_Pos)
	{
		delete Iter_Pos->second;
	}


	delete sEntityManager;
};

/*************Hero getter setter***********************/
const char* EntityManager::GetHeroName() {
	return first_hero_->GetName();
};

int EntityManager::GetHeroHPAll() {
	return first_hero_->GetHPAll();
};

void EntityManager::SetHeroHPAll(int HP_All) {
	first_hero_->SetHPAll(HP_All);
};

int EntityManager::GetHeroSPAll() {
	return first_hero_->GetSPAll();
};

void EntityManager::SetHeroSPAll(int SP_All) {
	first_hero_->SetSPAll(SP_All);
};


int EntityManager::GetHeroHP() {
	return first_hero_->GetHP();
};

void EntityManager::SetHeroHP(int HP) {
	first_hero_->SetHP(HP);
};

int EntityManager::GetHeroSP() {
	return first_hero_->GetSP();
};

void EntityManager::SetHeroSP(int SP) {
	first_hero_->SetSP(SP);
};

int EntityManager::GetHeroAttack() {
	return first_hero_->GetAttack();
};

void EntityManager::SetHeroAttack(int ATK) {
	first_hero_->SetAttack(ATK);
};

int EntityManager::GetHeroDeffense() {
	return first_hero_->GetDeffense();
};

void EntityManager::SetHeroDeffense(int DEF) {
	first_hero_->SetDeffense(DEF);
};

int EntityManager::GetHeroLevel() {
	return first_hero_->GetLevel();
};

void EntityManager::SetHeroLevel(int LEV) {
	first_hero_->SetLevel(LEV);
};

int EntityManager::GetHeroGold() {
	return first_hero_->GetGold();
};

void EntityManager::SetHeroGold(int GOLD) {
	first_hero_->SetGold(GOLD);
};

/***************Set Monster map********************/
void EntityManager::SetMonsterMap(int hero_level) {
	int op = rand() % 6 - 3;
	int monster_level = hero_level + op;

	if(monster_level <= 0)
		monster_level = 1;

	monster_map_[MONSTER_KOBOLD] = new AliveObjectMonster(10, 10, 3, monster_level, MONSTER_KOBOLD, "코볼트");
	op = rand() % 6 - 3;
	monster_map_[MONSTER_GOBLIN] = new AliveObjectMonster(10, 10, 0, monster_level, MONSTER_GOBLIN, "고블린");
	op = rand() % 6 - 3;
	monster_map_[MONSTER_OGRE] = new AliveObjectMonster(20, 15, 5, monster_level, MONSTER_OGRE, "오우거");
};

//Setting first_monster
void EntityManager::SetFirstMonsterRandom() {
	int index = rand() % 3 + 1;
	first_monster_ = monster_map_.at(index);
}

/***************Moster getter setter******************/
int EntityManager::GetMonsterHP() {
	return first_monster_->GetHP();
};

void EntityManager::SetMonsterHP(int HP) {
	first_monster_->SetHP(HP);
};

int EntityManager::GetMonsterAttack() {
	return first_monster_->GetAttack();
};

void EntityManager::SetMonsterAttack(int ATK) {
	first_monster_->SetAttack(ATK);
};

int EntityManager::GetMonsterDeffense() {
	return first_monster_->GetDeffense();
};

void EntityManager::SetMonsterDeffense(int DEF) {
	first_monster_->SetDeffense(DEF);
};

int EntityManager::GetMonsterLevel() {
	return first_monster_->GetLevel();
};

void EntityManager::SetMonsterLevel(int LEV) {
	first_monster_->SetLevel(LEV);
};

char* EntityManager::GetMonsterName() {
	return first_monster_->GetName();
};

/*************Check State********************/
bool EntityManager::CheckHeroState() {
	return first_hero_->CheckState();
};

bool EntityManager::CheckMonsterState() {
	return first_monster_->CheckState();
};

/************for battle hp decrease***********/
void EntityManager::DecreaseHeroHp(int d_hp) {
	int hp = first_hero_->GetHP();
	first_hero_->SetHP(hp - d_hp);
};

void EntityManager::DecreaseMonsterHp(int d_hp) {
	int hp = first_monster_->GetHP();
	first_monster_->SetHP(hp - d_hp);
};
