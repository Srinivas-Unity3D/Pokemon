#pragma once
#include <string>
using namespace std;

enum class PokemonType;

class  Pokemon 
{
public:
    string name;
    PokemonType type;
    int health;

    Pokemon();

    Pokemon(string p_name, PokemonType p_type, int p_health);

    Pokemon(const Pokemon& other);

    ~Pokemon();

    void attack();
};