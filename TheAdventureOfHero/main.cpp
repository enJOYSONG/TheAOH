#include <iostream>
#include "Manager/GameManager.h"
using namespace std;

int main() {
	GameManager game_manager;

	game_manager.Init();

	while(true) {
		game_manager.ShowMenu();
		game_manager.SelectMenu();
	}
};
