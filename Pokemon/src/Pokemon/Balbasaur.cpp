#include "../../include/Pokemon/Balbasaur.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include <iostream>

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;
		Balbasaur::Balbasaur() :Pokemon("Balbasaur", PokemonType::GRASS, 100, {
			Move("VINE WHIP", 25),
			Move("TACKLE", 10)
			}) {}
		void Balbasaur::vineWhip(Pokemon* target)
		{
			cout << name << " used VINE WHIP!\n";
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

		void Balbasaur::attack(Pokemon* target) 
		{
			selectAndUseMove(target);
		}
	}
}