#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Battle
{
    BattleState BattleManager::battleState;

    void BattleManager::startBattle(Player* player, Pokemon* wildPokemon)
    {
        battleState.playerPokemon = player->chosenPokemon;
        battleState.wildPokemon = wildPokemon;
        battleState.playerTurn = true;
        battleState.battleOngoing = true;

        cout << "A wild " << wildPokemon->getName() << " appeared.\n";
        battle();
    }


    void BattleManager::battle()
    {
        while (battleState.battleOngoing)
        {
            if (battleState.playerTurn)
            {
                battleState.playerPokemon->selectAndUseMove(battleState.wildPokemon);
            }
            else
            {
                battleState.wildPokemon->selectAndUseMove(battleState.playerPokemon);
            }

            updateBattleState();

            battleState.playerTurn = !battleState.playerTurn;

            N_Utility::Utility::waitForEnter();
        }

        handleBattleOutcome();
    }

    void BattleManager::handleBattleOutcome() {

        if (battleState.playerPokemon->isFainted())
        {
            cout << battleState.playerPokemon->getName()<< " has fainted! You lose the battle.\n";
        }
        else 
        {
            cout << "You defeated the wild " << battleState.wildPokemon->getName()<< "!\n";
        }
    }

    void BattleManager::updateBattleState()
    {
        if (battleState.playerPokemon->isFainted())
        {
            battleState.battleOngoing = false;
        }
        else if (battleState.wildPokemon->isFainted())
        {
            battleState.battleOngoing = false;
        }
    }

    void BattleManager::stopBattle() 
    {
        battleState.battleOngoing = false;
    }
}