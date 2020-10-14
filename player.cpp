#include "player.h"

Player::Player()
{
	x_ = 22;
	y_ = 1;
	health_points_ = 100;
	max_health_points_ = 100;
	attack_ = 20;
	defense_ = 5;
	name_ = "The Hero";
	experience_ = 0;
	health_regen_ = 5;
}

void Player::Regen()
{
	health_points_ += health_regen_;
	health_points_ =
		std::min(health_points_, max_health_points_);
}


