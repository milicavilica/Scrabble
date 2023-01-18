#include <iostream>
#include <fstream>

using namespace std;

void Exit()
{
    cout << "You left the game!";
    return;
}
void AddNewWord()
{

}
void ChangeNumOfAvailableLetters(int& availableLettersCount)
{
    cout << "Current available letters per round count: " << availableLettersCount << endl;
    cout << "Insert desired available letters count: ";
    int lettersCount;
    cin >> lettersCount;
    if (lettersCount >= 2 && lettersCount <= 100)
    {
        availableLettersCount = lettersCount;
        cout << "You changed the available letters count per round to " << availableLettersCount << endl;
    }
    cout << endl;
}
void ChangeNumOfRounds(int& roundsCount)
{
    cout << "Current rounds count: " << roundsCount << endl;
    cout << "Insert desired rounds count: ";
    int roundsCnt;
    cin >> roundsCnt;
    if (roundsCnt >= 1 && roundsCnt <= 25)
    {
        roundsCount = roundsCnt;
        cout << "You changed the rounds count to " << roundsCount << endl;
    }
    cout << endl;
}
void Settings(int& roundsCount, int& availableLettersCount)
{
    cout << "Settings menu:" << endl;
    cout << "1. Change number of available letters per round" << endl;
    cout << "2. Chane number of rounds" << endl;
    int choice;
    cin >> choice;
    cout << endl;
    switch (choice) 
    {
    case 1: ChangeNumOfAvailableLetters(availableLettersCount);
        break;
    case 2: ChangeNumOfRounds(roundsCount);
        break;
    default:
        break;
    }
}
void NewGame(int& rounds, int& lettersPerRound)
{
    // printing (10) random letters in Test\ScrabbleTest
    //CHECKING IF THE WORD EXISTS IN THE DICTIONARY IN Test\ScrabbleTest
}
bool Menu(int& roundsCount, int& availableLettersCount)
{
    cout << "Menu:" << endl;
    cout << "1. Start new game" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Add new word" << endl;
    cout << "4. Exit" << endl;
    char choice;
    cin >> choice;
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