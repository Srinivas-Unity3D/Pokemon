#include "../../include/Pokemon/Squirtle.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons 
	{
		using namespace std;
		Squirtle::Squirtle() :Pokemon("Squirtle", PokemonType::WATER, 100, 35) {}
		void Squirtle::waterSplash(Pokemon& target) 
		{
			cout << name << " uses Water splash on " << target.getName() << "!\n";
			target.TakeDamage(35);
		}

		void Squirtle::attack(Pokemon& target) 
		{
			waterSplash(target);
		}
	}
}