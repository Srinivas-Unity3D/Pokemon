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

        virtual void attack(Pokemon* target) = 0;

        void TakeDamage(int damage);

        bool isFainted() const;

        void heal();

        string getName() const;
        int getHealth() const;
    };
}