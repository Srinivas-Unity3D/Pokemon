#include "include/Utility/Utility.hpp"
#include "include/Character/ProfessorOak.hpp"
#include "include/Pokemon/PokemonType.hpp"
#include "include/Main/Game.h"
#include "include/Pokemon/grass.hpp"
#include "include/Character/Player/Player.hpp"
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