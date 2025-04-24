#pragma once
#include <string>
using namespace std;

namespace N_Pokemon
{
    enum class PokemonType;

    class  Pokemon
    {
    protected:
        string name;
        PokemonType type;
        int health;
        int maxHealth;
        int attackPower;
    public:
        Pokemon();

        Pokemon(string p_name, PokemonType p_type, int p_health, int attackPower);

        Pokemon(const Pokemon& other);

        ~Pokemon();

        void attack(Pokemon& target);

        void TakeDamage(int damage);

        bool isFainted() const;

        void heal();

        string getName() const;

    };
}