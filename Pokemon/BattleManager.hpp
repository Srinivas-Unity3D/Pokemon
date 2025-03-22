#pragma once
#include "Pokemon.hpp"
#include "Player.hpp"

class BattleManager 
{
public:
	void startBattle(Player &player, Pokemon &wildPokemon);

private:
	void battle(Pokemon& playerPokemon, Pokemon& wildPokemon);
	void handleBattleOutcome(Pokemon &playerChosenPokemon, bool playerWon);
};
