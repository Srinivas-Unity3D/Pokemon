#pragma once
#include "../Character/Player/Player.hpp"
#include "BattleState.hpp"

using namespace N_Player;


namespace N_Battle 
{
	class BattleManager
	{
	public:
		void startBattle(Player& player, Pokemon& wildPokemon);

	private:
		BattleState battleState;

		void battle();
		void handleBattleOutcome();
		void updateBattleState();
	};
}
