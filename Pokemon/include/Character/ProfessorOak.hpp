#pragma once
#include "Player/Player.hpp"
using namespace std;
using namespace N_Player;

namespace N_Character 
{
    class ProfessorOak {
    public:
        string name;

        ProfessorOak(string p_name);

        void greetPlayer(Player& player);

        void offerPokemonChoices(Player& player);

        void explainMainQuest(Player& player);
    };
}
