#include "../../include/Battle/WildEncounterManager.hpp"
#include <cstdlib> 
#include <ctime>   

WildEncounterManager::WildEncounterManager() {
    srand(time(0)); 
}

Pokemon WildEncounterManager::getRandomPokemonFromGrass(const Grass& grass) {
    int randomIndex = rand() % grass.wildPokemonList.size();
    return grass.wildPokemonList[randomIndex];
}