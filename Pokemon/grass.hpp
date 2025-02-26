#pragma once
#include<string>
#include <vector>
using namespace std;

class Pokemon;
struct Grass
{
	string environmentType;
	vector<Pokemon> wildPokemongList;
	int encounterRate;
};