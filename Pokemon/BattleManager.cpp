#include "Pokemon.hpp"
#include "BattleManager.hpp"
#include "Utility.hpp"
#include <iostream>

using namespace std;


void BattleManager::startBattle(Player &player, Pokemon &wildPokemon) 
{
    cout << "A wild " << wildPokemon.name << " appeared.\\n";
    battle(player.chosenPokemon, wildPokemon);
}


void BattleManager :: battle(Pokemon &playerPokemon, Pokemon &wildPokemon) {

    while (!playerPokemon.isFainted() && !wildPokemon.isFainted()) {
        playerPokemon.attack(wildPokemon); 

        if (!wildPokemon.isFainted()) {
            wildPokemon.attack(playerPokemon); 
        }

        Utility::waitForEnter();
    }

    handleBattleOutcome(playerPokemon, playerPokemon.isFainted());

    if (playerPokemon.isFainted()) {
        cout << playerPokemon.name << " has fainted! You lose the battle.\\n";
    }
    else {
        cout << "You defeated the wild " << wildPokemon.name << "!\\n";
    }

}

void BattleManager::handleBattleOutcome(Pokemon &palyerChosenPokemon, bool playerWon) {
    if (playerWon) {
        cout << palyerChosenPokemon.name << " is victorious! Keep an eye on your Pokémon's health.\n";
    }
    else {
        cout << "Oh no! " << palyerChosenPokemon.name << " fainted! You need to visit the PokeCenter.\n";
        Utility::waitForEnter();
        cout << "Game Over.\n";
    }
}