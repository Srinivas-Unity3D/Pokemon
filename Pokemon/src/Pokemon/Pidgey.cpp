#include "../../include/Pokemon/Pidgey.hpp";
#include "../../include/Pokemon/PokemonType.hpp";
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons 
	{
		using namespace std;

		Pidgey::Pidgey() :Pokemon("Pidgey", PokemonType::NORMAL, 100, 35) {}
		
		void Pidgey::wingAttack(Pokemon &target) 
		{
			cout << name << " use wing attack on " << target.getName() << "!\n";
			target.TakeDamage(35);
		}
	}
}

