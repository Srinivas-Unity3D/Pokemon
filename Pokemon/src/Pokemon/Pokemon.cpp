#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/Move.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../ParalyzedEffect.hpp"
#include <iostream>
#include <vector>
#include <limits>

namespace N_Pokemon
{

    Pokemon::Pokemon() {
        name = "Unknown";
        type = PokemonType::NORMAL;
        health = 100;
    }

    Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, int p_attackPower) {
        name = p_name;
        type = p_type;
        maxHealth = p_health;
        attackPower = p_attackPower;
        health = maxHealth;

        appliedEffect = nullptr;
    }

    Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health, std::vector<Move> _moves) {
        name = p_name;
        type = p_type;
        maxHealth = p_health;
        health = maxHealth;
        attackPower = 0;

        for (Move move : _moves) 
        {
            moves.push_back(move);
        }
    }

    Pokemon::Pokemon(const Pokemon& other) {
        name = other.name;
        type = other.type;
        health = other.health;
        maxHealth = other.maxHealth;
        attackPower = other.attackPower;
    }

    Pokemon::~Pokemon() {
        // Destructor message removed
    }

   /* void Pokemon::attack(Pokemon* target)
    {
        int damage = attackPower;
        cout << name << " attacks " << target->name << " for " << damage << " damage!\n";
        target->TakeDamage(damage);
    }*/

    void Pokemon::attack(Move selectedMove, Pokemon* target)
    {
        target->TakeDamage(selectedMove.power);
    }

    void Pokemon::TakeDamage(int damage)
    {
        health -= damage;

        if (health <= 0)
        {
            health = 0;
        }
    }

    bool Pokemon::isFainted() const
    {
        return health <= 0;
    }

    void Pokemon::heal()
    {
        health = maxHealth;
    }

    std::string Pokemon::getName() const 
    {
        return name;
    }

    int Pokemon::getHealth() const 
    {
        return health;
    }

    void Pokemon::selectAndUseMove(Pokemon* target) 
    {
        printAvailableMoves();
        int choice = selectMove();
        Move selectedMove = moves[choice - 1];
        
        useMove(selectedMove, target);
    }

    void Pokemon::printAvailableMoves() 
    {
        std::cout << name << "'s available moves:\n";

        for (size_t i = 0; i < moves.size(); ++i) {
            std::cout << i + 1 << ": " << moves[i].name << " (Power: " << moves[i].power << ")\n";
        }
    }

    int Pokemon::selectMove() 
    {
        int choice;
        while (true)
        {
            std::cout << "Choose a move: ";
            if (std::cin >> choice)
            {
                if (choice >= 1 && choice <= static_cast<int>(moves.size()))
                {
                    return choice;
                }
                else
                {
                    std::cout << "Invalid choice. Please enter a number between 1 and " << moves.size() << ".\n";
                }
            }
            else
            {
                std::cout << "Invalid input. Please enter a valid integer.\n";
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            }
        }
    }

    void Pokemon::useMove(Move selectedMove, Pokemon* target) 
    {
        std::cout << name << " used " << selectedMove.name << "!\n";
        attack(selectedMove, target);

        N_Utility::Utility::waitForEnter();

        std::cout << "...\n";
        N_Utility::Utility::waitForEnter();

        if (target->isFainted()) 
        {
            std::cout << target->name << " fainted!\n";
        } 
        else 
        {
            std::cout << target->name << " has " << target->health << " HP left.\n";
        }     
    }

    void Pokemon::reduceAttackPower(int reducedDamage)
    {
        attackPower -= reducedDamage;
    }

    bool Pokemon::canAttack()
    {
        if (appliedEffect == nullptr)
            return true;
        else
            return appliedEffect->turnEndEffect(this);
    }

    bool Pokemon::canApplyEffect() { return appliedEffect == nullptr; }

    void Pokemon::applyEffect(N_StatusEffects::StatusEffectType effectToApply)
    {
        switch (effectToApply)
        {
        case N_StatusEffects::StatusEffectType::PARALYZED:
            appliedEffect = new N_StatusEffects::ParalyzedEffect();
            appliedEffect->applyEffect(this);
            break;
        default:
            appliedEffect = nullptr;
        }
    }

    void Pokemon::clearEffect() { appliedEffect = nullptr; }
}