#pragma once
#include <string>
#include "../../Pokemon/PokemonType.hpp"
#include "../../Pokemon/Pokemon.hpp"

using namespace std;

class Player {
public:
    string name;
    Pokemon chosenPokemon;

    Player(); 
    Player(string p_name, Pokemon p_chosenPokemon); 

    void choosePokemon(int choice); 
};