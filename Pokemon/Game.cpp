#include "Game.h"
#include "Player.hpp"
#include "PokemonType.hpp"
#include "Utility.hpp"
#include "WildEncounterManager.hpp"
#include "BattleManager.hpp"
#include <iostream>
using namespace std;

Game::Game() {
    forestGrass = { "Forest",
                   {Pokemon("Pidgey", PokemonType::NORMAL, 50, 10),
                    Pokemon("Caterpie", PokemonType::BUG, 60, 15),
                    Pokemon("Zubat", PokemonType::POISON, 80, 20)},
                   70 };
}

void Game::gameLoop(Player& player) {
    BattleManager battleManager;
    bool keepPlaying = true;

    while (keepPlaying) {
        Utility::clearConsole();
        std::cout << "\nWhat would you like to do next, " << player.name << "?\n";
        std::cout << "1. Battle Wild Pokemon\n";
        std::cout << "2. Visit PokeCenter\n";
        std::cout << "3. Challenge Gyms\n";
        std::cout << "4. Enter Pokemon League\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        Utility::clearInputBuffer();

        switch (choice) {
        case 1: {
            WildEncounterManager encounterManager;
            Pokemon wildPokemon = encounterManager.getRandomPokemonFromGrass(forestGrass);
            battleManager.startBattle(player, wildPokemon);
            break;
        }
        case 2: {
            std::cout << "You head to the PokeCenter.\n";
            player.chosenPokemon.heal(); 
            std::cout << player.chosenPokemon.name << "'s health is fully restored!\n";
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

    std::cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
}