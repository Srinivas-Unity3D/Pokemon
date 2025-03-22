#include "Pokemon.hpp"
#include <iostream>
#include "PokemonType.hpp"
using namespace std;



Pokemon::Pokemon() {
    name = "Unknown";
    type = PokemonType::NORMAL;
    health = 50;
}

Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health) {
    name = p_name;
    type = p_type;
    health = p_health;
}

Pokemon::Pokemon(const Pokemon& other) {
    name = other.name;
    type = other.type;
    health = other.health;
}

Pokemon::~Pokemon() {
    // Destructor message removed
}

void Pokemon:: attack(Pokemon& target) 
{
    int damage = 10;
    cout << name << " attacks " << target.name << " for " << damage << " damage!\\n";
    target.TakeDamage(damage);
}

void Pokemon::TakeDamage(int damage) 
{
    health -= damage;

    if (health <= 0) 
    {
        health = 0;
    }
}

bool Pokemon::isFainted() const
{
    return health <= 0;
}