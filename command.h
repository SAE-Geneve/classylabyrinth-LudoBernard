#pragma once

#include "player.h"
#include "world.h"

class Command
{
public:
	void North();
	void South();
	void East();
	void West();

	void Attack();

	void Tick();
	void ShowHelp();
	char GetCommand();
	void ShowState();
	void ExecuteCommand();

	void CheckEnemies();
	

private:
	World world_;
};
