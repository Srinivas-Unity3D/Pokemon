#include "../../include/Pokemon/Pikachu.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include <iostream>


namespace N_Pokemon 
{
	namespace N_Pokemons 
	{
		using namespace std;

		Pikachu::Pikachu() :Pokemon("Pikachu", PokemonType::ELECTRIC, 100, 20) {}

		void Pikachu::thunderShock(Pokemon& target) 
		{
			cout << name << " use Thunder Shock on " << target.name << "!\n";
			target.TakeDamage(20);
		}
	}
}