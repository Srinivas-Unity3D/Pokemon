#include "Pokemon.hpp"
#include <iostream>
#include "PokemonType.hpp"
using namespace std;



Pokemon::Pokemon() {
    name = "Unknown";
    type = PokemonType::NORMAL;
    health = 100;
}

Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health, int p_attackPower) {
    name = p_name;
    type = p_type;
    maxHealth = p_health;
    attackPower = p_attackPower;
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
    int damage = attackPower;
    cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
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

void Pokemon::heal() 
{
    health = maxHealth;
}