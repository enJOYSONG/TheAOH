#include <iostream>
#include "EntityManager.h"
#include "../Hero/AliveObjectHero.h"

using namespace std;

EntityManager* EntityManager::sEntityManager = NULL;

void EntityManager::Init() {
	first_hero_ = new AliveObjectHero;
};

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