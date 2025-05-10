#include "../../include/Main/Game.h"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Battle/WildEncounterManager.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Pokemon/Pidgey.hpp"
#include "../../include/Pokemon/Caterpie.hpp"
#include "../../include/Pokemon/Zubat.hpp"
#include <iostream>
using namespace N_Utility;
using namespace N_Battle;
using namespace N_Pokemons;

namespace N_Main
{
	Game::Game() {
		forestGrass = { "Forest",
					   {new Pidgey(),
						new Caterpie(),
						new Zubat()},
					   70 };
	}

	Game::~Game() 
	{
		delete(wildPokemon);
	}

	void Game::visitPokemonCenter(Player* player) 
	{
		cout << "You head to the PokeCenter.\n";
		player->chosenPokemon->heal();
		cout << player->chosenPokemon->getName() << "'s health is fully restored!\n";
	}

	void Game::gameLoop(Player* player) {
		BattleManager battleManager;
		bool keepPlaying = true;

		while (keepPlaying) {
			Utility::clearConsole();
			cout << "\nWhat would you like to do next, " << player->name << "?\n";
			cout << "1. Battle Wild Pokemon\n";
			cout << "2. Visit PokeCenter\n";
			cout << "3. Challenge Gyms\n";
			cout << "4. Enter Pokemon League\n";
			cout << "5. Quit\n";
			cout << "Enter your choice: ";
			int choice;
			cin >> choice;

			Utility::clearInputBuffer();

			switch (choice) {
			case 1: {
				WildEncounterManager encounterManager;
				Pokemon* wildPokemon = encounterManager.getRandomPokemonFromGrass(forestGrass);
				battleManager.startBattle(player, wildPokemon);
				delete(wildPokemon);
				break;
			}
			case 2: {
				visitPokemonCenter(player);
				break;
			}
			case 5: {
				keepPlaying = false;
				break;
			}
			default: {
				std::cout << "That's not a valid choice. Try again!\n";
				break;
			}
			}

			Utility::waitForEnter();
		}

		cout << "Goodbye, " << player->name << "! Thanks for playing!\n";
	}
}

