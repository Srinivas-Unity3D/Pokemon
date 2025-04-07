#include "../../include/Pokemon/Balbasaur.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;
		Balbasaur::Balbasaur() :Pokemon("Balbasaur", PokemonType::GRASS, 100, 35) {}
		void Balbasaur::vineWhip(Pokemon& target) 
		{
			cout << name << " uses vine whip on " << target.getName() << "!\n";
			target.TakeDamage(35);
		}

		void Balbasaur::attack(Pokemon& target) 
		{
			vineWhip(target);
		}
	}
}