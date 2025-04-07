#pragma once
#include "../Pokemon/grass.hpp" 
using namespace N_Pokemon;

namespace N_Battle
{
	class WildEncounterManager {
	public:
		WildEncounterManager();
		Pokemon* getRandomPokemonFromGrass(const Grass& grass);
	};
}