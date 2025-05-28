#include "ParalyzedEffect.hpp"
#include "include/Pokemon/Pokemon.hpp"
#include <iostream>

namespace N_Pokemon
{
	namespace N_StatusEffects
	{
		void ParalyzedEffect::applyEffect(Pokemon* target)
		{
			std::cout << target->getName() << " is paralyzed! It may not be able to move!\n";
			turnLeft = rand() % 3 + 1;
		}

		std::string ParalyzedEffect::getEffectName()
		{
			return "Paralyzed";
		}

		bool ParalyzedEffect::turnEndEffect(Pokemon* target)
		{
			if (turnLeft <= 0)
			{
				clearEffect(target);
				return true;
			}

			turnLeft--;
			int paralysis_chance = rand() % 4;
			if (paralysis_chance == 0)
			{
				std::cout << target->getName() << " is paralyzed! It can't move!\n";
				return false;
			}

			std::cout << target->getName() << " shakes off the paralysis momentarily and can move!\n";
			return true;
		}

		void ParalyzedEffect::clearEffect(Pokemon* target)
		{
			std::cout << target->getName() << " is no longer paralyzed!\n";
			target->clearEffect();
		}
	}
}