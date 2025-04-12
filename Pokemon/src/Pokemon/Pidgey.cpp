#include "../../include/Pokemon/Pidgey.hpp";
#include "../../include/Pokemon/PokemonType.hpp";
#include "../../include/Utility/Utility.hpp"
#include "../../include/Pokemon/Move.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_Pokemons 
	{
		using namespace std;

		Pidgey::Pidgey() :Pokemon("Pidgey", PokemonType::NORMAL, 100, {
			Move("GUST", 15),
			Move("TACKLE", 10)
			}) {}
		
		void Pidgey::wingAttack(Pokemon* target) 
		{
			cout << name << " used WING ATTACK!\n";
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

		void Pidgey::attack(Move selectedMove, Pokemon* target) {
			Pokemon::attack(selectedMove, target);

			if (selectedMove.name == "GUST")
			{
				if (rand() % 100 < 20)
				{
					cout << "... and blew the opponent away!\n";
					N_Battle::BattleManager::stopBattle();
					N_Utility::Utility::waitForEnter();
				}
			}
		}
	}
}

