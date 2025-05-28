#pragma once
#include "IStatusEffect.hpp"
#include "include/Pokemon/StatusEffects/StatusEffectType.hpp"
#include <string>

namespace N_Pokemon 
{
	namespace N_StatusEffects 
	{
		class ParalyzedEffect : public IStatusEffect 
		{
		private:
			int turnLeft;
		public:
			void applyEffect(Pokemon* target) override;
			std::string getEffectName() override;
			bool turnEndEffect(Pokemon* target) override;
			void clearEffect(Pokemon* target) override;
		};
	}
}
