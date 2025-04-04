#pragma once
#include "Pokemon.hpp"

namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		class Charmander:public Pokemon
		{
		private:
			void flameBurst(Pokemon& target);

		public:
			Charmander();
		};
	}
}
