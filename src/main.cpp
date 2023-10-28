#include <iostream>
#include <ctime>
#include "assets/enums/GameClasses.hpp"
#include "assets/classes/Character.hpp"
#include "assets/classes/Game.hpp"

using namespace std;

int main() {
  srand((unsigned int)time(NULL));

  Character* player = new Character("Spectre", GameClasses::SCOUT);
  Character* enemy = new Character("Banshee", GameClasses::WARRIOR);
  Game game(player, enemy);

  game.startGame();

  player->~Character();
  delete player;

  enemy->~Character();
  delete enemy;

  game.~Game();

  return 0;
}