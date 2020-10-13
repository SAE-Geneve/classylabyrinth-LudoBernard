#include <iostream>
#include "command.h"
#include "player.h"
#include "world.h"

Command cmd;
	
	// Now check if there is an enemy within range.
	// for each enemy within range:
	// show enemy description.

/*
 	if (TileType::ENEMY == get_tile_at_position(player.x, player.y + 1))
		show_description(get_enemy(player.x, player.y + 1));
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y - 1))
		show_description(get_enemy(player.x, player.y - 1));
	if (TileType::ENEMY == get_tile_at_position(player.x + 1, player.y))
		show_description(get_enemy(player.x + 1, player.y));
	if (TileType::ENEMY == get_tile_at_position(player.x - 1, player.y))
		show_description(get_enemy(player.x - 1, player.y));
 */

int main() {
	Player player;
	std::cout << "Welcome in the Maze!\n";
	cmd.ShowHelp();
	while (true) {
		cmd.ShowState();
		player.Print();
		cmd.CheckEnemies();
		cmd.ExecuteCommand();
	}
	return 0;
}
