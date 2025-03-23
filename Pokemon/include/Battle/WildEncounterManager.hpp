#pragma once
#include <vector>
#include "../Pokemon/grass.hpp" 

class WildEncounterManager {
public:
	WildEncounterManager();
	Pokemon getRandomPokemonFromGrass(const Grass& grass);
};
