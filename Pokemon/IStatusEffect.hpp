#pragma once
#include <string>

namespace N_Pokemon {
	class Pokemon; 

	class IStatusEffect 
	{
	public:
		virtual void applyEffect(Pokemon* target) = 0;
		virtual std::string getEffectName() = 0;
		virtual bool turnEndEffect(Pokemon* target) = 0;
		virtual void clearEffect(Pokemon* target) = 0;
		virtual ~IStatusEffect() = default;
	};
}