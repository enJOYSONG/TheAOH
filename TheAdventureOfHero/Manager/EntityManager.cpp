#include <iostream>
#include "EntityManager.h"
#include "../Hero/AliveObjectHero.h"
#include "../Monster/AliveObjectMonster.h"

using namespace std;

EntityManager* EntityManager::sEntityManager = NULL;

void EntityManager::Init() {
	first_hero_ = new AliveObjectHero;
	first_monster_ = new AliveObjectMonster;
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

/*************Check State********************/
bool EntityManager::CheckHeroState() {
	return first_hero_->CheckState();
};

bool EntityManager::CheckMonsterState() {
	return first_monster_->CheckState();
};