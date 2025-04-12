#include "../../include/Pokemon/Squirtle.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons 
	{
		using namespace std;
		Squirtle::Squirtle() :Pokemon("Squirtle", PokemonType::WATER, 100, {
			Move("Water Splash", 35),
			Move("TACKLE", 10)
			}) {
		}
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
			selectAndUseMove(target);
		}
	}
}