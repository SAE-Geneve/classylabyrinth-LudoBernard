#pragma once

#include <string>

class Character
{
public:
	void Print();
	int GetX();
	int GetY();
	int GetHealth();
	int GetAttack();
	int GetDefense();
	void SetX(int x);
	void SetY(int y);
	void SetHealth(int health);
	
protected:
	int x_;
	int y_;
	int health_points_;
	int max_health_points_;
	int attack_;
	int defense_;
	std::string name_;
	int experience_;
	int health_regen_;
};