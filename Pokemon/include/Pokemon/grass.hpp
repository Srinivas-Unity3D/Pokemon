#pragma once
#include <vector>
#include <string>
#include "Pokemon.hpp"

namespace N_Pokemon 
{
	class Pokemon;
	struct Grass
	{
		std::string environmentType;
		std::vector<Pokemon*> wildPokemonList;
		int encounterRate;
	};
}
