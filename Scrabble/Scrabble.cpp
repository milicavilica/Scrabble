#include <iostream>
#include <fstream>

using namespace std;

const int CURRENT_AVAILABLE_LETTERS_ARR_SIZE = 100;
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
    else
    {
        cout << "Input must be a number between 2 and 100!";
    }
    cout << endl;
}
void ChangeNumOfRounds(int& roundsCount)
{
    cout << "Current rounds count: " << roundsCount << endl;
    cout << "Insert desired rounds count: ";
    int roundsCnt;
    cin >>roundsCnt;
    if (roundsCnt >= 1 && roundsCnt <= 25)
    {
        roundsCount = roundsCnt;
        cout << "You changed the rounds count to " << roundsCount << endl;
    }
    else
    {
        cout << "Input must be a number between 1 and 25!" << endl;
    }
    cout << endl;
}
void Settings(int& roundsCount, int& availableLettersCount)
{
    cout << "Settings menu:" << endl;
    cout << "1. Change number of available letters per round" << endl;
    cout << "2. Chane number of rounds" << endl;
    char choice;
    cin >> choice;
    cout << endl;
    switch (choice) 
    {
    case '1': ChangeNumOfAvailableLetters(availableLettersCount);
        break;
    case '2': ChangeNumOfRounds(roundsCount);
        break;
    default:
        cout << "Wrong input!" << endl << endl;
        break;
    }
}
int GetLenght(char* charArray)
{
    int i = 0;
    while (charArray[i] != '\0')
    {
        i++;
    }
    return i;
}
bool FindWord(char* currentWord, char* charArr)
{
    if (currentWord[0] != charArr[0])
    {
        return false;
    }
    else
    {
        if (currentWord[1] != charArr[1])
        {
            return false;
        }
    }
    if (GetLenght(currentWord) != GetLenght(charArr))
    {
        return false;
    }
    int i = 0;
    bool flag = true;
    while (currentWord[i] != '\0' && charArr[i] != '\0')
    {
        if (currentWord[i] != charArr[i])
        {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}
bool DoesWordConsistOfAvailableLettersOnly(const char* availableLetters,char* word, int& availableLettersCount)
{
    int i = 0;
    bool* lettersUsed = new bool[availableLettersCount] {};
    while (word[i] != '\0')
    {
        int j = 0;
        while (availableLetters[j] != '0')
        {
            if (word[i] == availableLetters[j] && !lettersUsed[j])
            {
                lettersUsed[j] = true;
                break;
            }
            j++;
        }
        i++;
    }
    int wordLenght = GetLenght(word);
    i = 0;
    for (int j = 0; j < availableLettersCount; j++)
    {
        if (lettersUsed[j]) i++;
    }
    delete[] lettersUsed;
    if (i == wordLenght) return true;
    else return false;
}
void MakeWordAllCaps(char* currentWord)
{
    int i = 0;
    while (currentWord[i] != '\0')
    {
        if (currentWord[i] >= 97 && currentWord[i] <= 121)
        {
            currentWord[i] -= 32;
        }
        i++;
    }
}
void NewGame(int& rounds, int& lettersPerRound)
{
    for (int i = 0; i < rounds; i++)
    {
        char currentAvailableLetters[CURRENT_AVAILABLE_LETTERS_ARR_SIZE] = { '\0' };
        cout << "Round " << i + 1 << endl;
        cout << "Available letters:";
        for (int i = 0; i < lettersPerRound; i++)
        {
            char c = 'a' + rand() % 26;
            currentAvailableLetters[i] = c;
            cout<< " " << c;
        }
        char currentWord[CURRENT_AVAILABLE_LETTERS_ARR_SIZE] = { '\0' };
        cout << endl << "Type a word using the available letters: ";
        cin.getline(currentWord, CURRENT_AVAILABLE_LETTERS_ARR_SIZE);
        int wordLenght = GetLenght(currentWord);
        if (!DoesWordConsistOfAvailableLettersOnly(currentAvailableLetters, currentWord, lettersPerRound))
        {
            cout << "Invalid word!" << endl << "Try again: " << endl << endl;
            continue;
        }

        MakeWordAllCaps(currentWord);

        ifstream a;
        a.open("Scrabble Words.txt");

        bool flag = false;
        while (!a.eof())
        {
            char charArr[1024] = { '\0' };
            a >> charArr;
            if (FindWord(currentWord, charArr) == true)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "Valid word! Plus " << wordLenght << " points!" << endl << endl;
        }
        else
        {
            cout << "The word does not exist!" << endl << endl;
        }
        a.close();
    }
    
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