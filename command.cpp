#include <vector>
#include <iostream>
#include "command.h"
#include "world.h"

#include "player.h"

void Command::North()
{
	Player player = world_.GetPlayer();
	// If the location is not empty do NOTHING!
	if (world_.GetTileAtPosition(player.GetX(), player.GetY() - 1) != '.') {
		return;
	}
	else {
		player.SetY(player.GetY() - 1);
		world_.SetPlayer(player);
	}
}

void Command::South()
{
	Player player = world_.GetPlayer();
	// If the location is not empty do NOTHING!
	if (world_.GetTileAtPosition(player.GetX(), player.GetY() + 1) != '.') {
		return;
	}
	else {
		player.SetY(player.GetY() + 1);
		world_.SetPlayer(player);
	}
}

void Command::East()
{
	Player player = world_.GetPlayer();
	// If the location is not empty do NOTHING!
	if (world_.GetTileAtPosition(player.GetX() + 1, player.GetY()) != '.') {
		return;
	}
	else {
		player.SetX(player.GetX() + 1);
		world_.SetPlayer(player);
	}
}

void Command::West()
{
	Player player = world_.GetPlayer();
	// If the location is not empty do NOTHING!
	if (world_.GetTileAtPosition(player.GetX() - 1, player.GetY()) != '.') {
		return;
	}
	else {
		player.SetX(player.GetX() - 1);
		world_.SetPlayer(player);
	}
}

void Command::Attack()
{
	Player player = world_.GetPlayer();
	std::vector<Enemy> enemy_vec;
	if (world_.GetTileAtPosition(player.GetX(), player.GetY() - 1) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX(), player.GetY() - 1));
	if (world_.GetTileAtPosition(player.GetX(), player.GetY() + 1) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX(), player.GetY() + 1));
	if (world_.GetTileAtPosition(player.GetX() - 1, player.GetY()) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX() - 1, player.GetY()));
	if (world_.GetTileAtPosition(player.GetX() + 1, player.GetY()) == 'E')
		enemy_vec.push_back(world_.GetEnemy(player.GetX() + 1, player.GetY()));
	//Doesn't work
	for(auto enemy : enemy_vec)
	{
		enemy.SetHealth(enemy.GetHealth() - player.GetAttack() + enemy.GetDefense());
		if(enemy.GetHealth() <= 0)
		{
			world_.EraseEnemy(enemy);
		}
	}
}

void Command::Tick()
{
	// FIXME Suppose to have enemy moving soon(tm).
	// Life regen.
	Player player = world_.GetPlayer();
	player.Regen();
	world_.MoveEnemies();
}

void Command::ShowHelp()
{
	std::cout << "Valid options:\n"
		<< "\t[q]uit  -> quit the game.\n" << "\t[n]orth -> move north.\n"
		<< "\t[s]outh -> move south.\n" << "\t[e]ast -> move east.\n"
		<< "\t[w]est -> move west.\n" << "\t[a]ttack -> attack.\n"
		<< "\t[h]elp-> show help and options.\n";
}

char Command::GetCommand()
{
	std::cout << "> ";
	std::string command_str;
	std::getline(std::cin, command_str);
	return command_str[0];
}

void Command::ShowState()
{
	Player player = world_.GetPlayer();
	std::cout << "Maze :\n" << "\nPlayer(X:" << player.GetX() << ", Y:" << player.GetY() << ") :\n";
	for (int i = player.GetY() - 1; i < player.GetY() + 2; i++) {
		for (int j = player.GetX() - 4; j < player.GetX() + 2; j++) {
			std::cout << (char)world_.GetTileAtPosition(j, i);
		}
		std::cout << std::endl;
	}
}


void Command::ExecuteCommand()
{
		switch (GetCommand()) {
		case 'q':
			std::cout << "Bye!\n";
			exit(0);
		case 'n':
			North();
			break;
		case 's':
			South();
			break;
		case 'e':
			East();
			break;
		case 'w':
			West();
			break;
		case 'a':
			Attack();
			break;
		case 'h':
		default:
			ShowHelp();
			break;
		}
		Tick();
	}

void Command::CheckEnemies()
{
	Player player = world_.GetPlayer();
	if (world_.GetTileAtPosition(player.GetX(), player.GetY() + 1) == 'E')
	{
		Enemy enemy = world_.GetEnemy(player.GetX(), player.GetY() + 1);
		printf("Enemy near!\n");
		enemy.Print();
	}
	if (world_.GetTileAtPosition(player.GetX(), player.GetY() - 1) == 'E')
	{
		auto enemy = world_.GetEnemy(player.GetX(), player.GetY() - 1);
		printf("Enemy near!\n");
		enemy.Print();
	}
	if (world_.GetTileAtPosition(player.GetX() + 1, player.GetY()) == 'E')
	{
		auto enemy = world_.GetEnemy(player.GetX() + 1, player.GetY());
		printf("Enemy near!\n");
		enemy.Print();
	}
	if (world_.GetTileAtPosition(player.GetX() - 1, player.GetY()) == 'E')
	{
		auto enemy = world_.GetEnemy(player.GetX() - 1, player.GetY());
		printf("Enemy near!\n");
		enemy.Print();
	}
}


/*
void attack() {
	Player player = get_player();
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y - 1))
		enemy_vec.push_back(get_enemy(player.x, player.y - 1));
	if (TileType::ENEMY == get_tile_at_position(player.x, player.y + 1))
		enemy_vec.push_back(get_enemy(player.x, player.y + 1));
	if (TileType::ENEMY == get_tile_at_position(player.x - 1, player.y))
		enemy_vec.push_back(get_enemy(player.x - 1, player.y));
	if (TileType::ENEMY == get_tile_at_position(player.x + 1, player.y))
		enemy_vec.push_back(get_enemy(player.x + 1, player.y));
	for (const auto& enemy : enemy_vec)
		cross_attack(player, enemy);
}
 */

