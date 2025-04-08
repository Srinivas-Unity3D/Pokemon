#include "../../include/Pokemon/Charmander.hpp"
#include "../../include//Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;
		Charmander::Charmander() :Pokemon("Charmander", PokemonType::FIRE, 100, 35) {}
		
		void Charmander::flameBurst(Pokemon* target) 
		{
			cout << name << " uses FLAME THROWER!\n";
			N_Utility::Utility::waitForEnter();
			cout << "...\n";
			N_Utility::Utility::waitForEnter();
			target->TakeDamage(attackPower);
			
			if (target->isFainted()) 
			{
				cout << target->getName() << "fainted!\n";
			}
			else
			{
				cout << target->getName() << " has " << target->getHealth() << "HP left.\n";
			}

			N_Utility::Utility::waitForEnter();

		}

		void Charmander::attack(Pokemon* target) 
		{
			flameBurst(target);
		}
	}
}
