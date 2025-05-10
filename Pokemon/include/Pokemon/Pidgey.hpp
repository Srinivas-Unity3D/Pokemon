#pragma once
#include "Pokemon.hpp";


namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		class Pidgey: public Pokemon
		{
		private:
			void wingAttack(Pokemon* target);
		public:
			Pidgey();
			void attack(Move selectedMove, Pokemon* target) override;
		};
	}
}
