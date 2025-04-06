#include "include/Character/ProfessorOak.hpp"
#include "include/Main/Game.h"
#include <limits> 
#include <string>
using namespace N_Character;
using namespace N_Main;


int main() {
    Pokemon charmander("Charmander", PokemonType::FIRE, 100, 25); 

    ProfessorOak* professor = new ProfessorOak("Professor Oak");
    Player* player = new Player("Ash", charmander);

    professor->greetPlayer(*player);
    professor->offerPokemonChoices(*player);

    professor->explainMainQuest(*player);

    Game* game = new Game();
    game->gameLoop(*player);

    delete(professor);
    delete(player);
    delete(game);

    return 0;
}