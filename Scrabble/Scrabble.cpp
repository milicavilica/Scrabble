#include <iostream>

using namespace std;

void Exit()
{
    cout << "You left the game!";
    return;
}
void AddNewWord()
{

}
void Settings()
{

}
void NewGame()
{

}
void Menu()
{
    cout << "Menu:" << endl;
    cout << "1. Start new game" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Add new word" << endl;
    cout << "4. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1: NewGame();
        break;
    case 2: Settings();
        break;
    case 3: AddNewWord();
        break;
    case 4: Exit();
        break;

    default:
        break;
    }
}
int main()
{
    Menu();
}