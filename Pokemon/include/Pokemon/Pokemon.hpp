#pragma once
#include <string>
#include <vector>
using namespace std;

namespace N_Pokemon
{
    struct Move;
    enum class PokemonType;

    class  Pokemon
    {
    protected:
        string name;
        PokemonType type;
        int health;
        int maxHealth;
        int attackPower;
        void printAvailableMoves();
        int selectMove();
        void useMove(Move selectedMove,Pokemon* target);
        vector<Move> moves;

    public:
        Pokemon();

        Pokemon(string p_name, PokemonType p_type, int p_health, int attackPower);
        Pokemon(string p_name, PokemonType p_type, int p_health, vector<Move> availableMoves);

        Pokemon(const Pokemon& other);

        ~Pokemon();
        virtual void attack(Move selectedMove, Pokemon* target) = 0;

        void TakeDamage(int damage);
        void reduceAttackPower(int reducedDamage);

        bool isFainted() const;

        void heal();

        string getName() const;
        int getHealth() const;

        void selectAndUseMove(Pokemon* target);
    };
}