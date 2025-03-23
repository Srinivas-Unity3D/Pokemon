#include "include/Character/ProfessorOak.hpp"
#include "include/Main/Game.h"
#include <limits> 
#include <string>
using namespace N_Character;
using namespace N_Main;


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