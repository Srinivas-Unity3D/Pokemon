#pragma once
#include "../../Pokemon/PokemonType.hpp"
#include "../../Pokemon/Pokemon.hpp"

using namespace std;
using namespace N_Pokemon;

namespace N_Player 
{
    class Player {
    public:
        string name;
        Pokemon* chosenPokemon;

        Player();
        Player(string p_name);

        void choosePokemon(int choice);
    };
}

