#pragma once
#include "IStatusEffect.hpp"
using namespace std;

namespace N_Pokemon 
{
	namespace N_StatusEffect 
	{
		class ParalyzedEffect : public IStatusEffect 
		{
		private:
			int turnLeft;
		public:
			void applyEffect(Pokemon* target) override;
			string getEffectName() override;
			bool turnEndEffect(Pokemon* target) override;
			void clearEffect(Pokemon* target) override;
		};
	}
}
