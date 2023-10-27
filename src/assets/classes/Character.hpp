#include <iostream>
#include <string>
#include <ctime>
#include "../headfiles/maxMinStats.hpp"

using namespace std;

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
private:
  string name;
  double damage;
  double health;
  int luck;

public:
  Character();
  Character(string name);
  ~Character();
  void printStats(string role);
  string getName();
  double getDamage();
  double getHealth();
  int getLuck();
  void setDamage(double damage);
  void setHealth(double health);
};

Character::Character() {}

Character::Character(string name)
{
  this->name = name;
  this->damage = rand() % (MAX_DAMAGE - MIN_DAMAGE + 1) + MIN_DAMAGE;
  this->health = rand() % (MAX_HEALTH - MIN_HEALTH + 1) + MIN_HEALTH;
  this->luck = rand() % (MAX_LUCK - MIN_LUCK + 1) + MIN_LUCK;
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
  cout << "Damage: " << this->damage << endl;
  cout << "Health: " << this->health << endl;
  cout << "Luck: " << this->luck << "%" << endl;
}

// Getters
string Character::getName() {
  return this->name;
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

// Setters
void Character::setDamage(double damage) {
  this->damage = damage;
}
void Character::setHealth(double health) {
  this->health = health;
}

#endif
