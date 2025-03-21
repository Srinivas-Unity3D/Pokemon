#pragma once
#include<string>
#include <vector>
#include "Pokemon.hpp"
using namespace std;

class Pokemon;
struct Grass
{
	string environmentType;
	vector<Pokemon> wildPokemonList;
	int encounterRate;
};