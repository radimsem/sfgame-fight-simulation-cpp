#include <iostream>
#include <string>
#include <ctime>
#include "../enums/GameClasses.hpp"
#include "../headfiles/maxMinStats.hpp"

using namespace std;

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
private:
  string name;
  GameClasses gameClass;
  string gameClassName;
  string mainAttributeName;
  int mainAttribute;
  int constitution;
  int weaponDamage;
  int defendChance;
  double damage;
  double health;
  int luck;
  int level;

public:
  Character();
  Character(string name, GameClasses gameClass);
  ~Character();

  // Public methods
  void printStats(string role);

  // Getters
  string getName();
  GameClasses getGameClass();
  double getDamage();
  double getHealth();
  int getLuck();
  int getDefendChance();

  // Setters
  void setDamage(double damage);
  void setHealth(double health);
};

Character::Character() {}

Character::Character(string name, GameClasses gameClass)
{
  this->name = name;
  this->luck = rand() % (MAX_LUCK - MIN_LUCK + 1) + MIN_LUCK;
  this->level = rand() % (MAX_LEVEL - MIN_LEVEL + 1) + MIN_LEVEL;
  
  int averageAttributeValue = MAX_MAIN_ATTRIBUTE - MIN_CONSTITUTION;
  do
  {
    this->mainAttribute = rand() % (MAX_MAIN_ATTRIBUTE - MIN_MAIN_ATTRIBUTE + 1) + MIN_MAIN_ATTRIBUTE;
    this->constitution = rand() % (MAX_CONSTITUTION - MIN_CONSTITUTION + 1) + MIN_CONSTITUTION;
  } while (this->mainAttribute - averageAttributeValue != averageAttributeValue - this->constitution);

  switch (gameClass)
  {
  case GameClasses::MAGE:
    this->gameClassName = "Mage";
    this->mainAttributeName = "Intelligence";
    this->weaponDamage = rand() % (MAX_WEAPON_DAMAGE_MAGE - MIN_WEAPON_DAMAGE_MAGE + 1) + MIN_WEAPON_DAMAGE_MAGE;
    this->health = this->constitution * 2 * (this->level + 1);
    this->defendChance = 0;
    break;
  
  case GameClasses::SCOUT:
    this->gameClassName = "Scout";
    this->mainAttributeName = "Dexterity";
    this->weaponDamage = rand() % (MAX_WEAPON_DAMAGE_SCOUT - MIN_WEAPON_DAMAGE_SCOUT + 1) + MIN_WEAPON_DAMAGE_SCOUT;
    this->health = this->constitution * 4 * (this->level + 1);
    this->defendChance = 50;
    break;

  case GameClasses::WARRIOR:
    this->gameClassName = "Warrior";
    this->mainAttributeName = "Strength";
    this->weaponDamage = rand() % (MAX_WEAPON_DAMAGE_WARRIOR - MIN_WEAPON_DAMAGE_WARRIOR + 1) + MIN_WEAPON_DAMAGE_WARRIOR;
    this->health = this->constitution * 5 * (this->level + 1);
    this->defendChance = 25;
    break;
  }
  this->gameClass = gameClass;

  this->damage = this->weaponDamage * (1 + this->mainAttribute / 10);
}

Character::~Character()
{
  delete this;
}

/**
 * Prints the character's stats, that were generated with the construction
 * @param role describe if the character is Player or Enemy
*/
void Character::printStats(string role) {
  cout << role << ": " << this->name << endl;
  cout << "Class: " << this->gameClassName << endl;
  cout << "Level: " << this->level << endl;
  cout << this->mainAttributeName << ": " << this->mainAttribute << endl;
  cout << "Constitution: " << this->constitution << endl;
  cout << "Luck: " << this->luck << "%" << endl;
  cout << "Weapon damage: " << this->weaponDamage << endl;
  cout << "Damage: " << this->damage << endl;
  cout << "Health: " << this->health << endl;
  
  if (this->defendChance > 0)
  {
    cout << "Defending chance: " << this->defendChance << "%" << endl;
  }
  
}

// Getters
string Character::getName() {
  return this->name;
}
GameClasses Character::getGameClass() {
  return this->gameClass;
}
double Character::getDamage() {
  return this->damage;
}
double Character::getHealth() {
  return this->health;
}
int Character::getLuck() {
  return this->luck;
}
int Character::getDefendChance() {
  return this->defendChance;
}

// Setters
void Character::setDamage(double damage) {
  this->damage = damage;
}
void Character::setHealth(double health) {
  this->health = health;
}

#endif
