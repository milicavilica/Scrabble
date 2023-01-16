#include <iostream>

using namespace std;

int roundsCount = 10;
int availableLettersCount = 10;

void Menu();
void Exit()
{
    cout << "You left the game!";
    return;
}
void AddNewWord()
{

}
void ChangeNumOfAvailableLetters()
{
    cout << "Insert desired available letters count: ";
    int lettersCount;
    cin >> lettersCount;
    if (lettersCount >= 2 && lettersCount <= 100)
    {
        availableLettersCount = lettersCount;
        cout << "You changed the available letters count per round to " << availableLettersCount << endl;
    }
    cout << endl;
    Menu();
}
void ChangeNumOfRounds()
{
    cout << "Insert desired rounds count: ";
    int roundsCnt;
    cin >> roundsCnt;
    if (roundsCnt >= 1 && roundsCnt <= 25)
    {
        roundsCount = roundsCnt;
        cout << "You changed the rounds count to " << roundsCount << endl;
    }
    cout << endl;
    Menu();
}
void Settings()
{
    cout << "Settings menu:" << endl;
    cout << "1. Change number of available letters per round" << endl;
    cout << "2. Chane number of rounds" << endl;
    int choice;
    cin >> choice;
    cout << endl;
    switch (choice) 
    {
    case 1: ChangeNumOfAvailableLetters();
        break;
    case 2: ChangeNumOfRounds();
        break;
    default:
        break;
    }
}
void NewGame(int lettersPerRound, int rounds)
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
    cout << endl;
    switch (choice)
    {
    case 1: NewGame(availableLettersCount, roundsCount);
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