#include "../../include/Pokemon/Caterpie.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		using namespace std;

		Caterpie::Caterpie() :Pokemon("Caterpie", PokemonType::BUG, 100, {
			Move("BugBite", 20),
			Move("TACKLE", 10)
			}) {}

		void Caterpie::bugBite(Pokemon* target) 
		{
			cout << name << " used BugBite!\n";
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

		void Caterpie::attack(Pokemon* target) 
		{
			selectAndUseMove(target);
		}
	}
}