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
			Move("RAPID SPIN", 5),
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

		void Squirtle::attack(Move selectedMove, Pokemon* target) {
			Pokemon::attack(selectedMove, target);

			if (selectedMove.name == "RAPID SPIN")
			{
				int hits = (rand() % 4) + 2;

				for (int i = 0; i < hits; ++i) {
					Pokemon::attack(selectedMove, target);
				}

				cout << "... and hit " << hits << " times!\\n";
			}
		}
	}
}