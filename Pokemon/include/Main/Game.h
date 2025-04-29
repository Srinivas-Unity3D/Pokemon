#pragma once
#include "../Pokemon/grass.hpp"
#include "../Character/Player/Player.hpp"
using namespace N_Player;

namespace N_Main 
{
	class Game
	{
	private:
		Grass forestGrass;
	public:
		Game();
		void gameLoop(Player& player);
	};

}
