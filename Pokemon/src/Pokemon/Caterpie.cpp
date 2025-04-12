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
			Move("STICKY WEB", 10),
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

		void Caterpie::attack(Move selectedMove, Pokemon* target) {
			Pokemon::attack(selectedMove, target);

			if (selectedMove.name == "STICKY WEB")
			{
				int reducedDamage = 5;
				target->reduceAttackPower(reducedDamage);
				cout << target->getName() << "'s next attack will be reduced by " << reducedDamage << " damage!\n";
			}
		}
	}
}