#include <iostream>
#include "Manager/GameManager.h"
using namespace std;

int main() {
	GameManager game_manager;

	game_manager.Init();

	game_manager.ShowAndSelectMenu();
};