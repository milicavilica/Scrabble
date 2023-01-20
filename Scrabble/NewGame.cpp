/**
*
* Solution to course project #08
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Militsa Toncheva
* @idnumber 2MI0600216
* @compiler VC
*
* <new game functions>
*
*/
#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

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
bool DoesWordConsistOfAvailableLettersOnly(const char* availableLetters, char* word, int& availableLettersCount)
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
void MakeWordAllLow(char* currentWord)
{
    int i = 0;
    while (currentWord[i] != '\0')
    {
        if (currentWord[i] >= 65 && currentWord[i] <= 90)
        {
            currentWord[i] += 32;
        }
        i++;
    }
}

void GenerateLetters(int lettersPerRound, char* currentAvailableLetters)
{
    srand(time(NULL));
    for (int i = 0; i < lettersPerRound; i++)
    {
        char c = 'a' + rand() % 26;
        currentAvailableLetters[i] = c;
        cout << " " << c;
    }
}
bool IsWordValid(char* currentWord)
{
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
    a.close();
    return flag;
}
void NewGame(int& rounds, int& lettersPerRound)
{
    int points = 0;
    for (int i = 0; i < rounds; i++)
    {
        char currentAvailableLetters[CURRENT_AVAILABLE_LETTERS_ARR_SIZE] = { '\0' };
        cout << "Round " << i + 1  << "/" << rounds << endl;
        cout << "----------------------------------------" << endl;
        cout << "Available letters:";
        GenerateLetters(lettersPerRound, currentAvailableLetters);
        char currentWord[MAX_WORD_LENGHT] = { '\0' };
        cout << endl << "Type a word using the available letters: ";
        cin.getline(currentWord, CURRENT_AVAILABLE_LETTERS_ARR_SIZE);
        int wordLenght = GetLenght(currentWord);
        cout << endl;

        MakeWordAllLow(currentWord);
        if (!DoesWordConsistOfAvailableLettersOnly(currentAvailableLetters, currentWord, lettersPerRound))
        {
            cout << "Invalid word!" << endl << "Try again!" << endl << endl;
            continue;
        }

        MakeWordAllCaps(currentWord);
        bool flag = IsWordValid(currentWord);

        if (flag)
        {
            cout << "Valid word! Plus " << wordLenght << " points!" << endl;
            points += wordLenght;
            cout << "Current points: " << points << endl << endl;
        }
        else
        {
            cout << "The word does not exist!" << endl << endl;
        }
    }
    cout << "TOTAL POINTS: " << points << endl << endl;
}