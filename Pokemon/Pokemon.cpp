#include "Pokemon.hpp"
#include <iostream>
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

void Pokemon:: attack() { cout << name << " attacks with a powerful move!\n"; }