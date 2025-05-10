#include "../../../include/Pokemon/PokemonChoice.hpp"
#include "../../../include/Pokemon/Charmander.hpp"
#include "../../../include/Pokemon/Balbasaur.hpp"
#include "../../../include/Pokemon/Squirtle.hpp"
#include "../../../include/Pokemon/Pikachu.hpp" 
#include "../../../include/Character/Player/Player.hpp"
#include "../../../include/Utility/Utility.hpp"

#include "iostream"
using namespace std;
using namespace N_Pokemons;

namespace N_Player 
{
    Player::Player() {
        name = "Trainer";
    }

    Player::Player(string p_name) {
        name = p_name;
    }

    void Player::choosePokemon(int choice) {
        switch ((PokemonChoice)choice) {
        case PokemonChoice::CHARMANDER:
            chosenPokemon = new Charmander();
            break;
        case PokemonChoice::BULBASAUR:
            chosenPokemon = new Balbasaur();
            break;
        case PokemonChoice::SQUIRTLE:
            chosenPokemon = new Squirtle();
            break;
        default:
            chosenPokemon = new Pikachu();
            break;
        }
        cout << "Player " << name << " chose " << chosenPokemon->getName() << "!\n";
        N_Utility::Utility::waitForEnter();
    }
}

