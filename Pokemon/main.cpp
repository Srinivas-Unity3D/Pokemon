#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include "Utility.hpp"
#include "Player.hpp"
#include <iostream>
#include <limits> 
#include <string>


using namespace std;


class Pokemon {
public:
    string name;
    PokemonType type;
    int health;

    Pokemon() {
        name = "Unknown";
        type = PokemonType::NORMAL;
        health = 50;
    }

    Pokemon(std::string p_name, PokemonType p_type, int p_health) {
        name = p_name;
        type = p_type;
        health = p_health;
    }

    Pokemon(const Pokemon& other) {
        name = other.name;
        type = other.type;
        health = other.health;
    }

    ~Pokemon() {
        // Destructor message removed
    }

    void attack() { std::cout << name << " attacks with a powerful move!\n"; }
};

class ProfessorOak {
public:
    string name;

    ProfessorOak(string p_name) { name = p_name; }

    void greetPlayer(Player& player) {
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
        Utility::waitForEnter();
        cout << name
            << ": My name is Oak. People call me the Pokemon Professor!\n";
        Utility::waitForEnter();
        cout << name << ": But enough about me. Let's talk about you!\n";
        Utility::waitForEnter();
    }

    void offerPokemonChoices(Player& player) {
        cout
            << name
            << ": First, tell me, what’s your name? \t [Please Enter Your Name]\n";
        getline(std::cin, player.name);
        cout << name << ": Ah, " << player.name
            << "! What a fantastic name!\n";
        Utility::waitForEnter();
        cout << name
            << ": You must be eager to start your adventure. But first, "
            "you’ll need a Pokemon of your own!\n";
        Utility::waitForEnter();

        cout
            << name
            << ": I have three Pokemon here with me. They’re all quite feisty!\n";
        Utility::waitForEnter();
        cout << name << ": Choose wisely...\n";
        cout << "1. Charmander - The fire type. A real hothead!\n";
        cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
        cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

        int choice;
        cout
            << name
            << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;

        player.choosePokemon(choice);
        Utility::waitForEnter();
    }

    void explainMainQuest(Player& player) {
        
        Utility::clearConsole();

        cout << "Professor Oak: " << player.name
            << "!, I am about to explain you about your upcoming grand "
            "adventure.\n";
        Utility::waitForEnter();
        cout << "Professor Oak: You see, becoming a Pokemon Master is no easy "
            "feat. It takes courage, wisdom, and a bit of luck!\n";
        Utility::waitForEnter();
        cout
            << "Professor Oak: Your mission, should you choose to accept it—and "
            "trust me, you really don’t have a choice—is to collect all the "
            "Pokemon Badges and conquer the Pokemon League.\n";
        Utility::waitForEnter();

        cout << "\n"
            << player.name
            << ": Wait... that sounds a lot like every other Pokemon game "
            "out there...\n";
        Utility::waitForEnter();
        cout << "Professor Oak: Shhh! Don't break the fourth wall, "
            << player.name << "! This is serious business!\n";
        Utility::waitForEnter();

        cout << "\nProfessor Oak: To achieve this, you’ll need to battle wild "
            "Pokemon, challenge gym leaders, and of course, keep your "
            "Pokemon healthy at the PokeCenter.\n";
        Utility::waitForEnter();
        cout << "Professor Oak: Along the way, you'll capture new Pokemon to "
            "strengthen your team. Just remember—there’s a limit to how "
            "many Pokemon you can carry, so choose wisely!\n";
        Utility::waitForEnter();

        cout << "\n"
            << player.name << ": Sounds like a walk in the park... right?\n";
        Utility::waitForEnter();
        cout << "Professor Oak: Hah! That’s what they all say! But beware, "
            "young Trainer, the path to victory is fraught with "
            "challenges. And if you lose a battle... well, let’s just say "
            "you'll be starting from square one.\n";
        Utility::waitForEnter();

        cout << "\nProfessor Oak: So, what do you say? Are you ready to "
            "become the next Pokemon Champion?\n";
        Utility::waitForEnter();
        cout << "\n" << player.name << ": Ready as I’ll ever be, Professor!\n";
        Utility::waitForEnter();

        cout
            << "\nProfessor Oak: That’s the spirit! Now, your journey begins...\n";
        Utility::waitForEnter();
        cout << "Professor Oak: But first... let's just pretend I didn't "
            "forget to set up the actual game loop... Ahem, onwards!\n";
        Utility::waitForEnter();
    }
};

void gameLoop(Player &player) {
    int choice;
    bool keepPlaying = true;

    while (keepPlaying) {
        Utility::clearConsole();

        cout << "\nWhat would you like to do next, " << player.name << "?\n";
        cout << "1. Battle Wild Pokemon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokemon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (choice) {
        case 1:
            cout << "You look around... but all the wild Pokemon are on "
                "vacation. Maybe try again later?\n";
            break;
        case 2:
            cout
                << "You head to the PokeCenter, but Nurse Joy is out on a coffee "
                "break. Guess your Pokemon will have to tough it out for now!\n";
            break;
        case 3:
            cout << "You march up to the Gym, but it's closed for renovations. "
                "Seems like even Gym Leaders need a break!\n";
            break;
        case 4:
            cout << "You boldly step towards the Pokemon League... but the "
                "gatekeeper laughs and says, 'Maybe next time, champ!'\n";
            break;
        case 5:
            cout << "You try to quit, but Professor Oak's voice echoes: "
                "'There's no quitting in Pokemon training!'\n";
            cout << "Are you sure you want to quit? (y/n): ";
            char quitChoice;
            cin >> quitChoice;
            if (quitChoice == 'y' || quitChoice == 'Y') {
                keepPlaying = false;
            }
            break;
        default:
            cout << "That's not a valid choice. Try again!\n";
            break;
        }

        Utility::waitForEnter();
    }

    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
}

int main() {
    Pokemon charmander("Charmander", PokemonType::FIRE, 100); 

    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);

    professor.explainMainQuest(player);

    gameLoop(player);

    return 0;
}