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
    int maxHealth;

    Pokemon();

    Pokemon(string p_name, PokemonType p_type, int p_health);

    Pokemon(const Pokemon& other);

    ~Pokemon();

    void attack(Pokemon& target);

    void TakeDamage(int damage);
   
    bool isFainted() const;
   
};