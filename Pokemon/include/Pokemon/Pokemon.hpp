#pragma once
#include <string>
#include <vector>
#include "StatusEffects/StatusEffectType.hpp"
#include "../../IStatusEffect.hpp"

namespace N_Pokemon
{
    struct Move;
    enum class PokemonType;

    using namespace N_StatusEffects;

    class Pokemon
    {
    protected:
        std::string name;
        PokemonType type;
        int health;
        int maxHealth;
        int attackPower;

        void printAvailableMoves();
        int selectMove();
        void useMove(Move selectedMove, Pokemon* target);

        std::vector<Move> moves;

    public:
        Pokemon();

        Pokemon(std::string p_name, PokemonType p_type, int p_health, int attackPower);
        Pokemon(std::string p_name, PokemonType p_type, int p_health, std::vector<Move> availableMoves);

        Pokemon(const Pokemon& other);

        IStatusEffect* appliedEffect;

        ~Pokemon();
        virtual void attack(Move selectedMove, Pokemon* target) = 0;

        void TakeDamage(int damage);
        void reduceAttackPower(int reducedDamage);

        bool isFainted() const;
        void heal();

        std::string getName() const;
        int getHealth() const;

        void selectAndUseMove(Pokemon* target);

        bool canAttack();
        void clearEffect();
        bool canApplyEffect();
        void applyEffect(N_StatusEffects::StatusEffectType effectToApply);
    };
}