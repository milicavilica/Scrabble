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
* <add new word functions>
*
*/
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