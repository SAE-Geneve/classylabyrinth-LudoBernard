#include "enemy.h"

Enemy::Enemy()
{
	health_points_ = 50;
	max_health_points_ = 50;
	attack_ = 10;
	defense_ = 2;
	name_ = "Gob";
	experience_ = 0;
	health_regen_ = 0;
}
