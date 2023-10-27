#include <iostream>
#include <ctime>
#include "./Character.hpp"
#include "../enums/Roles.hpp"

using namespace std;

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
  Character* player;
  Character* enemy;
  int firstAttacksCount;
  int secondAttacksCount;
  void startFight(Character* firstAttacker, Character* secondAttacker);
  void attack(Character* attacker, Character* defender);
  void endGame(Character* winner, int winnersAttacksCount);

public:
  Game(Character* player, Character* enemy);
  ~Game();
  void startGame();
};

Game::Game(Character* player, Character* enemy)
{
  this->player = player;
  this->enemy = enemy;
  this->firstAttacksCount = 0;
  this->secondAttacksCount = 0;
}

Game::~Game()
{
  delete this;
}

/**
 * Starts the game by showing both fighters and deciding who will start the attack first
*/
void Game::startGame() {
  this->player->printStats("Player");

  cout << endl;
  cout << "VS" << endl << endl;

  this->enemy->printStats("Enemy");

  cout << endl;
  cout << "Fight!" << endl << endl;

  int firstAttackerDecider = rand() % 2;

  if (firstAttackerDecider == Roles::PLAYER)
  {
    startFight(this->player, this->enemy);
  } else 
  {
    startFight(this->enemy, this->player);
  }
}

/**
 * Starts the fight, everytime handles who's turn is to attack and handles a winner of the game
 * @param firstAttacker an attacker who will start attacking first
 * @param secondAttacker an attacker who will attack after the first attacker
*/
void Game::startFight(Character* firstAttacker, Character* secondAttacker) {
  while (firstAttacker->getHealth() > 0 && secondAttacker->getHealth() > 0)
  {
    if (firstAttacksCount == secondAttacksCount)
    {
      attack(firstAttacker, secondAttacker);
      firstAttacksCount++;
    } else if (firstAttacksCount > secondAttacksCount)
    {
      attack(secondAttacker, firstAttacker);
      secondAttacksCount++;
    }
  }
  
  if (secondAttacker->getHealth() < 0)
  {
    endGame(firstAttacker, firstAttacksCount);
  } else if (firstAttacker->getHealth() < 0) 
  {
    endGame(secondAttacker, secondAttacksCount);
  }
}

/**
 * Handles the attacking process, sets new values to fighters and informs the attack in the console
 * @param attacker a character who's turn is to attack and deal damage
 * @param defender a character who will earn the damage by attacker
*/
void Game::attack(Character* attacker, Character* defender) {
  double criticalBonus = 1.0;
  int attackLuck = rand() % 100 + 1;

  if (attackLuck <= attacker->getLuck())
  {
    criticalBonus = 1.5;
  }

  defender->setHealth(defender->getHealth() - (attacker->getDamage() * criticalBonus));

  cout << "Attacker " << attacker->getName() << " damaged defender " << defender->getName() << " with damage " << attacker->getDamage() * criticalBonus;

  if (criticalBonus > 1)
  {
    cout << " which was critical";
  }
  cout << endl;
  
  cout << "Defender " << defender->getName() << " is alive with " << defender->getHealth() << "hp" << endl << endl;

  attacker->setDamage(attacker->getDamage() * 1.25);
}

/**
 * Ends the game by announcing the winner of the fight
 * @param winner a character who won the fight
 * @param winnersAttacksCount an integer that informs how many times the winner needed to attack to win
*/
void Game::endGame(Character* winner, int winnersAttacksCount) {
  cout << winner->getName() << " won on " << winnersAttacksCount << " attacks and with " << winner->getHealth() << "hp left";
}

#endif
