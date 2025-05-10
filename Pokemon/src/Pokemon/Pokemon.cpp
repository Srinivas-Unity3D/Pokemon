#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/Move.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>
#include<vector>

namespace N_Pokemon
{

    Pokemon::Pokemon() {
        name = "Unknown";
        type = PokemonType::NORMAL;
        health = 100;
    }

    Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health, int p_attackPower) {
        name = p_name;
        type = p_type;
        maxHealth = p_health;
        attackPower = p_attackPower;
        health = maxHealth;
    }

    Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health, vector<Move> _moves) {
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

    string Pokemon::getName() const 
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
        cout << name << "'s available moves:\n";

        for (size_t i = 0; i < moves.size(); ++i) {
            cout << i + 1 << ": " << moves[i].name << " (Power: " << moves[i].power << ")\n";
        }
    }

    int Pokemon::selectMove() 
    {
        int choice;
        while (true)
        {
            cout << "Choose a move: ";
            if (cin >> choice)
            {
                if (choice >= 1 && choice <= static_cast<int>(moves.size()))
                {
                    return choice;
                }
                else
                {
                    cout << "Invalid choice. Please enter a number between 1 and " << moves.size() << ".\n";
                }
            }
            else
            {
                cout << "Invalid input. Please enter a valid integer.\n";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
    }

    void Pokemon::useMove(Move selectedMove, Pokemon* target) 
    {
        cout << name << " used " << selectedMove.name << "!\n";
        attack(selectedMove, target);

        N_Utility::Utility::waitForEnter();

        cout << "...\n";
        N_Utility::Utility::waitForEnter();

        if (target->isFainted()) 
        {
            cout << target->name << " fainted!\n";
        } 
        else 
        {
            cout << target->name << " has " << target->health << " HP left.\n";
        }     
    }

    void Pokemon::reduceAttackPower(int reducedDamage)
    {
        attackPower -= reducedDamage;
    }
}