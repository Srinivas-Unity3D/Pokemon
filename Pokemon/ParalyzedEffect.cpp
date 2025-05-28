#include "ParalyzedEffect.hpp"
#include "include/Pokemon/Pokemon.hpp"
#include <iostream>
using namespace std;

namespace N_Pokemon
{
	namespace N_StatusEffect
	{
		void ParalyzedEffect::applyEffect(Pokemon* target)
		{
			cout << target->getName() << " is paralyzed! It may not be able to move!\n";
			turnLeft = rand() % 3 + 1;
		}

		string ParalyzedEffect::getEffectName()
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
				cout << target->getName() << " is paralyzed! It can't move!\n";
				return false;
			}

			cout << target->getName() << " shakes off the paralysis momentarily and can move!\n";
			return true;
		}

		void ParalyzedEffect::clearEffect(Pokemon* target)
		{
			cout << target->getName() << " is no longer paralyzed!\n";
			target->clearEffect(); // this need to be implemented
		}
	}
}