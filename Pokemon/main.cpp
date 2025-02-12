#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the world of Pokemon! I am professor Oak." << endl;
    cout << "You can choose one of the following pokemon:" << endl;
    cout << "1. Bulbasaur" << endl << "2. Charmander" << endl << "3. Squirtle" << endl;
    cout << "Which pokemon would you like to choose? Enter the number: ";
    int choice = 0;
    cin >> choice;

    if (choice == 1) 
    {
        cout << "You chose Bulbasaur! A wise choice." << endl;
    }
    else if (choice == 2) 
    {
        cout << "You chose Charmander! A fiery choice." << endl;
    }
    else if (choice == 3) 
    {
        cout << "You chose Squirtle! A cool choice." << endl;
    }
    else 
    {
        cout << "Invalid choice. Please restart the game." << endl;
    }
    
    return 0;
}
