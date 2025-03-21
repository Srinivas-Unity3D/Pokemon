#pragma once
#include <vector>
#include "Grass.hpp" 

class WildEncounterManager {
public:
	WildEncounterManager();
	Pokemon getRandomPokemonFromGrass(const Grass& grass);
};
