#include <iostream>
#include "EntityManager.h"
#include "../Hero/AliveObjectHero.h"

using namespace std;

EntityManager* EntityManager::sEntityManager = NULL;

void EntityManager::Init() {
	first_hero_ = new AliveObjectHero;
}