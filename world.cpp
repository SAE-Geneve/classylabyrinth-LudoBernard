#include <optional>
#include <cstdlib>
#include <ctime>

#include "world.h"
#include "enemy.h"


int World::xy_local(int x, int y)
{
	// We want the local array to be bound to the borders.
	if (x < 0) x = 0;
	if (x > 23) x = 23;
	if (y < 0) y = 0;
	if (y > 7) y = 7;
	// Return the position within the local world of the cursor.
	// As the array is singular dimention we use the largest value to
	// split it.
	return x + y * 24;
}


char World::GetTileAtPosition(int x, int y)
{
	return (char)world_[xy_local(x, y)];
}

Enemy World::GetEnemy(int x, int y)
{
	for(auto& enemy : enemies_)
	{
		if(enemy.GetX() == x && enemy.GetY() == y)
		{
			return enemy;
		}
	}
	return{};
}

void World::EraseEnemy(std::optional<Enemy> enemy)
{
	bool winGame = true;
	world_[xy_local(enemy->GetX(), enemy->GetY())] = '.';
	for (char block : world_)
	{
		if (block == 'E')
		{
			winGame = false;
		}
	}
	if (winGame == true)
	{
		printf("You slayed all the enemies and won the Maze!\nFeel free to roam around.\n");
	}
}

void World::SetEnemy(Enemy enemy)
{
	world_[xy_local(enemy.GetX(), enemy.GetY())] = 'E';
	enemies_.push_back(enemy);
}

Player World::GetPlayer()
{
	return local_player;
}

void World::SetPlayer(Player player)
{
	 // Erase the local player.
	 // Reinclude the new player.
	world_[xy_local(local_player.GetX(), local_player.GetY())] = '.';
	local_player = player;
	world_[xy_local(player.GetX(), player.GetY())] = 'P';
}

void World::MoveEnemies()
{
	// Doesn't work
	
	/*
	 srand(time(0));
	int direction = (rand() % 4);
	for (Enemy enemy : enemies_)
	{
		switch(direction)
		{
		case 1:
			world_[xy_local(enemy.GetX(), enemy.GetY())] = '.';
			enemy.SetY(enemy.GetY() - 1);
			SetEnemy(enemy);
			break;
		case 2:
			world_[xy_local(enemy.GetX(), enemy.GetY())] = '.';
			enemy.SetY(enemy.GetX() + 1);
			SetEnemy(enemy);
			break;
		case 3:
			world_[xy_local(enemy.GetX(), enemy.GetY())] = '.';
			enemy.SetY(enemy.GetY() + 1);
			SetEnemy(enemy);
			break;
		case 4:
			world_[xy_local(enemy.GetX(), enemy.GetY())] = '.';
			enemy.SetY(enemy.GetX() - 1);
			SetEnemy(enemy);
			break;
		}
		
	}
	printf("Enemies moved!");
	 */
	
	
}
