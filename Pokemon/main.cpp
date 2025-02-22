#include <iostream>
#include <string>
using namespace std;


enum class PokemonChoice 
{
    Charmander =1, 
    Bulbasaur,
    Squirtle,
    PIKACHU
};

enum class PokemonType
{
    FIRE,
    GRASS,
    WATER,
    ELECTRIC,
    NORMAL
};

class Pokemon
{
public:
    string name;
    PokemonType type;
    int health;

    Pokemon()
    {
        name = "Pikachu";
        type = PokemonType::ELECTRIC;
        health = 10;
        cout << "A new Pokemnon has been created with the defualt constructor!" << endl;
    }

    Pokemon(string p_name, PokemonType p_type, int p_health)
    {
        name = p_name;
        type = p_type;
        health = p_health;
        cout << "A new Pokemon named " << name << " has been created!" << endl;
    }

    Pokemon(const Pokemon &other) 
    {
        name = other.name;
        type = other.type;
        health = other.health;
        cout << "A new Pokemon has been copied from " << other.name << "!" << endl;
    }

    ~Pokemon() 
    {
        cout << name << " has released." << endl;
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

    Player() 
    {
        p_name = "Trainer";
        p_chosenPokemon = Pokemon();
        cout << "A new player named " << p_name << " has been created." << endl;
    }

    Player(string name, Pokemon chosenPokemon) {
        p_name = name;
        p_chosenPokemon = chosenPokemon;
        cout << "Player " << p_name << " has been created!"<<endl;
    }

    void choosePokemon(int choice) {
        switch ((PokemonChoice)choice) {
        case PokemonChoice::Charmander:
            p_chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 100);
            break;
        case PokemonChoice::Bulbasaur:
            p_chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 100);
            break;
        case PokemonChoice::Squirtle:
            p_chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 100);
            break;
        default:
            p_chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 100);
            break;
        }
        cout << "Player " << p_name << " chose " << p_chosenPokemon.name << "!" << endl;
    }
};

class ProfessorOak
{
public:
    string p_name;

    ProfessorOak(string name) {
        p_name = name;
    }


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
    
    Pokemon defaultPokemon; 
    Pokemon charmander("Charmander", PokemonType::FIRE, 100);
    cout << "Pokemon Details:\n";
    cout << "Name: " << defaultPokemon.name << "\nType: " << (int)defaultPokemon.type << "\nHealth: " << defaultPokemon.health << endl;
    cout << "Name: " << charmander.name << "\nType: " << (int)charmander.type << "\nHealth: " << charmander.health << endl;

    Pokemon bulbasaur("Bulbasaur", PokemonType::GRASS, 100); 
    Pokemon bulbasaurCopy = bulbasaur; 
    cout << "Original Pokemon Health: " << bulbasaur.health << endl;
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << endl;

    bulbasaurCopy.health = 80;
    cout << "After Modification:"<<endl;
    cout << "Original Pokemon Health: " << bulbasaur.health << endl;
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << endl;

    Pokemon squirtle("Squirtle", PokemonType::WATER, 100);

    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
    
    cout << "Professor Oak: " << player.p_chosenPokemon.name << " and you, " << player.p_name << ", are going to be the best of friends!"<<endl;
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!"<<endl;
    return 0;
}


