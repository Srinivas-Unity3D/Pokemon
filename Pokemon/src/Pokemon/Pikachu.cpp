#include "../../include/Pokemon/Pikachu.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>


namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;

		Pikachu::Pikachu() :Pokemon("Pikachu", PokemonType::ELECTRIC, 100, 20) {}

		void Pikachu::thunderShock(Pokemon* target) 
		{
			cout << name << " used Thunder Shock!\n";
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

		void Pikachu::attack(Pokemon* target) 
		{
			thunderShock(target);
		}
	}
}