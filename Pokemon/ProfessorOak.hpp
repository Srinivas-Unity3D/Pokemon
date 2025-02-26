#pragma once
#include <string>
#include "Player.hpp"
using namespace std;


class ProfessorOak {
public:
    string name;

    ProfessorOak(string p_name);

    void greetPlayer(Player& player);

    void offerPokemonChoices(Player& player);

    void explainMainQuest(Player& player);
};