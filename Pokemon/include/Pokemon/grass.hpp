#pragma once
#include<string>
#include <vector>
#include "Pokemon.hpp"

namespace N_Pokemon 
{
	class Pokemon;
	struct Grass
	{
		string environmentType;
		vector<Pokemon> wildPokemonList;
		int encounterRate;
	};
}
