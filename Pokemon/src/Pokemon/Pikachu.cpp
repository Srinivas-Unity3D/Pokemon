#include "../../include/Pokemon/Pikachu.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include <iostream>

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		Pikachu::Pikachu() :Pokemon("Pikachu", PokemonType::ELECTRIC, 100, {
			Move("THUNDER BOLT", 80),
			Move("THUNDER SHOCK", 20),
			Move("QUICK ATTACK", 10)
			}) {
		}

		void Pikachu::thunderShock(Pokemon* target) 
		{
			std::cout << name << " used Thunder Shock!\n";
			N_Utility::Utility::waitForEnter();
			std::cout << "...\n";
			N_Utility::Utility::waitForEnter();

			target->TakeDamage(attackPower);

			if (target->isFainted())
			{
				std::cout << target->getName() << " fainted!\n";
			}
			else
			{
				std::cout << target->getName() << " has " << target->getHealth() << " HP left.\n";
			}
			N_Utility::Utility::waitForEnter();
		}

		void Pikachu::attack(Move selectedMove, Pokemon* target) {
			if (selectedMove.name == "THUNDER BOLT")
			{
				if (rand() % 100 < 80)
				{
					Pokemon::attack(selectedMove, target);
					std::cout << "... and it hit successfully!\n";
				}
				else
					std::cout << "... but it missed!\n";
			}
			else
				Pokemon::attack(selectedMove, target);

			if (selectedMove.name == "THUNDER SHOCK")
			{
				if (target->canApplyEffect())
					target->applyEffect(N_StatusEffects::StatusEffectType::PARALYZED);
			}
		}
	}
}