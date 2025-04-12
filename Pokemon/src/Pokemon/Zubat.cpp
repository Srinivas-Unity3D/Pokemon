#include "../../include/Pokemon/Zubat.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include <iostream>

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;
		Zubat::Zubat() :Pokemon("Zubat", PokemonType::POISON, 100, {
			Move("Super Sonic", 25),
			Move("TACKLE", 10)
			}) {}
		void Zubat::supersonic(Pokemon* target) 
		{
			cout << name << " used Suporsonic attack!\n";
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

		void Zubat::attack(Pokemon* target) 
		{
			selectAndUseMove(target);
		}
	}
}