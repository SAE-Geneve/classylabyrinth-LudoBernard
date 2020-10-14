#pragma once

#include <optional>
#include <string>
#include <vector>

#include "enemy.h"
#include "player.h"

class World
{
private:
	std::string world_ =
		"########################" // 24 * 8
		"#.....E......E.....#..P#" // P is at (22, 1)
		"#######..#####..####...#"
		"#........#.............#"
		"#.E......#...E...E.....#"
		"#..##################..#"
		"#.........E............#"
		"########################";
	Player local_player{};
	std::vector<Enemy> enemies_;
public:
	int xy_local(int x, int y);
	char GetTileAtPosition(int x, int y);
	Enemy GetEnemy(int x, int y);
	void EraseEnemy(std::optional<Enemy> enemy);
	void SetEnemy(Enemy enemy);
	Player GetPlayer();
	void SetPlayer(Player player);
	void MoveEnemies();
};
