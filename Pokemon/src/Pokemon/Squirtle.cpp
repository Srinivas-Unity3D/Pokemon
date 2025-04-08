#include "../../include/Pokemon/Squirtle.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons 
	{
		using namespace std;
		Squirtle::Squirtle() :Pokemon("Squirtle", PokemonType::WATER, 100, 35) {}
		void Squirtle::waterSplash(Pokemon* target) 
		{
			cout << name << " used Water Splash!\n";
			N_Utility::Utility::waitForEnter();
			cout << "...\n";
			N_Utility::Utility::waitForEnter();

			target->TakeDamage(attackPower);

			if (target->isFainted())
			{
				cout << target->getName() << " fainted!\n";
			}
			else
			{
				cout << target->getName() << " has " << target->getHealth() << " HP left.\n";
			}
			N_Utility::Utility::waitForEnter();
		}

		void Squirtle::attack(Pokemon* target) 
		{
			waterSplash(target);
		}
	}
}