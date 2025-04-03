#include "../../include/Pokemon/Caterpie.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		using namespace std;

		Caterpie::Caterpie() :Pokemon("Caterpie", PokemonType::BUG, 100, 20) {}

		void Caterpie::bugBite(Pokemon& target) 
		{
			cout << name << " uses bugBite on " << target.getName() << "!\n";
			target.TakeDamage(20);
		}
	}
}