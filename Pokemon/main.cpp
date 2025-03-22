#include "Utility.hpp"
#include "ProfessorOak.hpp"
#include "PokemonType.hpp"
#include "Game.h"
#include "grass.hpp"
#include <iostream>
#include <limits> 
#include <string>

using namespace std;

Grass forestGrass = {
    "Forest",
    {{"Pidgey", PokemonType::NORMAL, 40, 20}, {"Caterpie", PokemonType::BUG, 35, 30}},
    70
};

Grass caveGrass = {
    "Cave",
    {{"Zubat", PokemonType::POISON, 30, 10}, {"Geodude", PokemonType::ROCK, 50, 5}},
    80
};

int main() {
    Pokemon charmander("Charmander", PokemonType::FIRE, 100, 25); 

    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    professor.explainMainQuest(player);

    Game game;
    game.gameLoop(player);

    return 0;
}