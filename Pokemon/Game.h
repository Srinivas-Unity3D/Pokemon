#pragma once
#include "grass.hpp"

class Player;
class Game
{
private:
	Grass forestGrass;
public:
	Game();
	void gameLoop(Player& player);
};
