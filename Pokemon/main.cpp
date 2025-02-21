#include <iostream>
#include <string>
using namespace std;


enum class PokemonChoice 
{
    Charmander =0, 
    Bulbasaur=1,
    Squirtle=2,
    InvalidChoice=3
};

enum class PokemonType
{
    Fire, 
    Electric, 
    Water, 
    Earth, 
    Normal
};

class Pokemon
{
public:
	string name;
	PokemonType type;
    int health;

    Pokemon() 
    {
    
    }

    Pokemon(string p_name, PokemonType p_type, int p_health) 
    {
        name = p_name;
        type = p_type;
        health = p_health;
    }

    void attack() 
    {
        cout << name << "attacks with a powerful move!" << endl;
    }
};

class Player 
{
public:
    string p_name;
    Pokemon p_chosenPokemon;

    void choosePokemon(int choice) {
        switch ((PokemonChoice)choice) {
        case PokemonChoice::Charmander:
            p_chosenPokemon = Pokemon("Charmander", PokemonType::Fire, 100);
            break;
        case PokemonChoice::Bulbasaur:
            p_chosenPokemon = Pokemon("Bulbasaur", PokemonType::Earth, 100);
            break;
        case PokemonChoice::Squirtle:
            p_chosenPokemon = Pokemon("Squirtle", PokemonType::Water, 100);
            break;
        default:
            p_chosenPokemon = Pokemon("Pikachu", PokemonType::Electric, 100);
            break;
        }
        cout << "Player " << p_name << " chose " << p_chosenPokemon.name << "!" << endl;
    }
};

class ProfessorOak
{
public:
    string p_name;

    void greetPlayer(Player &player) 
    {
        cout << p_name << ": Hello there! Welcome to the world of Pokemon!" << endl;
        cout << p_name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
        cout << p_name << ": But enough about me. Let's talk about you!" << endl;
    }

    void offerPokemonChoices(Player &player)
    {
        cout << p_name << ": First, tell me, what’s your name?" << endl;
        cin>>player.p_name;

        cout << p_name << ":  Ah, " << player.p_name << "! What a fantastic name!" << endl;
        cout << p_name << ":  You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!" << endl;

        cout << p_name << ":  I have three Pokemon here with me. They’re all quite feisty!" << endl;
        cout << p_name << ":  Choose wisely..." << endl;
        cout << "1. Charmander - The fire type. A real hothead!" << endl;
        cout << "2. Bulbasaur - The grass type. Calm and collected!" << endl;
        cout << "3. Squirtle - The water type. Cool as a cucumber!" << endl;

        int choice;
        cout << "Professor Oak: So, which one will it be? Enter the number of your choice: ";
        cin >> choice;
        player.choosePokemon(choice);
    }
};

int main() {
    
    ProfessorOak professor;
    Pokemon placeholderPokemon;
    Player player;

    placeholderPokemon.name = "Pikachu";
    placeholderPokemon.type = PokemonType::Electric;
    placeholderPokemon.health = 40;

    player.p_name = "Trainer";
    professor.p_name = "Professor Oak";

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
    
    cout << "Professor Oak: " << player.p_chosenPokemon.name << " and you, " << player.p_name << ", are going to be the best of friends!\n";
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!\n";
    
    return 0;
}


