#pragma once
#include "Pokemon.hpp"

namespace N_Pokemon
{
	namespace N_Pokemons 
	{
		class Pikachu : public Pokemon
		{
		private:
			void thunderShock(Pokemon* target);
		public:
			Pikachu();
			void attack(Move selectedMove, Pokemon* target) override;
		};
	}
}
