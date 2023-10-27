#include <iostream>
#include <ctime>
#include "assets/classes/Character.hpp"
#include "assets/classes/Game.hpp"

using namespace std;

int main() {
  srand((unsigned int)time(NULL));

  Character* player = new Character("Spectre");
  Character* enemy = new Character("Ghost");

  Game game(player, enemy);

  game.startGame();

  player->~Character();
  enemy->~Character();
  game.~Game();

  return 0;
}