#include "include/Pokemon/Pokemon.hpp"

using namespace N_Pokemon;
using namespace std;

class IStatusEffect 
{
public:
	virtual void applyEffect(Pokemon* target) = 0;
	virtual string getEffectName() = 0;
	virtual bool turnEndEffect(Pokemon* target) = 0;
	virtual void clearEffect(Pokemon* target) = 0;
	virtual ~IStatusEffect() = default;
};