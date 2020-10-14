#include <iostream>
#include "character.h"

void Character::Print()
{
	std::cout << "Health: " << health_points_ << std::endl << "Defense: "
		<< defense_ << std::endl << "Attack: " << attack_ << std::endl;
}

 int Character::GetX()
 {
	 return x_;
 }

 int Character::GetY()
 {
	 return y_;
 }

int Character::GetHealth()
{
	return health_points_;
}

int Character::GetAttack()
{
	return attack_;
}

int Character::GetDefense()
{
	return defense_;
}


 void Character::SetX(int x)
 {
	 x_ = x;
 }

 void Character::SetY(int y)
 {
	 y_ = y;
 }

void Character::SetHealth(int health)
{
	health_points_ = health;
}

