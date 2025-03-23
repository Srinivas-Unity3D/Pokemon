#pragma once
#include "../Pokemon/Pokemon.hpp"
#include "../Character/Player/Player.hpp"
#include "BattleState.hpp"


class BattleManager 
{
public:
	void startBattle(Player &player, Pokemon &wildPokemon);

private:
	BattleState battleState;

	void battle();
	void handleBattleOutcome();
	void updateBattleState();
};
