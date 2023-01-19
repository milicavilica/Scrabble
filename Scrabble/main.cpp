#include <iostream>
#include "Header.h"

using namespace std;

void Exit()
{
    cout << "You left the game!";
    return;
}
bool Menu(int& roundsCount, int& availableLettersCount)
{
    cout << "Menu:" << endl;
    cout << "-------------------" << endl;
    cout << "1. Start new game" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Add new word" << endl;
    cout << "4. Exit" << endl;
    cout << "-------------------" << endl;
    cout << "Enter your choice: ";
    char choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    switch (choice)
    {
    case '1': NewGame(roundsCount, availableLettersCount);
        break;
    case '2': Settings(roundsCount, availableLettersCount);
        break;
    case '3': AddNewWord();
        break;
    case '4': Exit();
        return false;
        break;

    default:
        cout << "Wrong input!" << endl << endl;
        break;
    }
    return true;
}
int main()
{
    int roundsCount = 10;
    int availableLettersCount = 10;
    
    while (Menu(roundsCount, availableLettersCount));
}