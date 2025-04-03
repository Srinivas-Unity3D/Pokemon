#include "../../include/Pokemon/Zubat.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;
		Zubat::Zubat() :Pokemon("Zubat", PokemonType::POISON, 100, 40) {}
		void Zubat::supersonic(Pokemon& target) 
		{
			cout << name << " uses suporsonic attack on " << target.getName() << "!\n";
			target.TakeDamage(40);
		}
	}
}