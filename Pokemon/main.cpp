#include "Utility.hpp"
#include "ProfessorOak.hpp"
#include "PokemonType.hpp"
#include "Game.h"
#include "grass.hpp"
#include <iostream>
#include <limits> 
#include <string>

using namespace std;


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