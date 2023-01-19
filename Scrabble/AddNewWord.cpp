#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void AddNewWord()
{
    cout << "Type the word you want to add: ";
    char newWord[MAX_WORD_LENGHT] = { '\0' };
    cin.getline(newWord, MAX_WORD_LENGHT);
    MakeWordAllCaps(newWord);
    cout << "-------------------------------" << endl;
    if (IsWordValid(newWord))
    {
        cout << "This word already exists!" << endl << endl;
        return;
    }
    else
    {
        ofstream file;
        file.open("Scrabble Words.txt", ios::out | ios::app);
        file << endl << newWord;
        file.close();
        cout << "You added the word " << newWord << "!" << endl << endl;
        return;
    }
}