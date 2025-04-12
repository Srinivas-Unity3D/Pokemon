#include "../../include/Pokemon/Pikachu.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include <iostream>


namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;

		Pikachu::Pikachu() :Pokemon("Pikachu", PokemonType::ELECTRIC, 100, {
			Move("THUNDER BOLT", 80),
			Move("TACKLE", 10)
			}) {
		}

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

		void Pikachu::attack(Move selectedMove, Pokemon* target) {
			if (selectedMove.name == "THUNDER BOLT")
			{
				if (rand() % 100 < 80)
				{
					Pokemon::attack(selectedMove, target);
					cout << "... and it hit successfully!\n";
				}
				else
					cout << "... but it missed!\n";
			}
			else
				Pokemon::attack(selectedMove, target);

		}
	}
}