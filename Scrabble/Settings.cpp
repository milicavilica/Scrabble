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
* <settings functions>
*
*/

#include <iostream>
#include "Header.h"

using namespace std;

const int MAX_LETTERS_COUNT_CHAR_ARR = 100;
const int MAX_ROUNDS_COUNT_CHAR_ARR = 100;

int PowerFunction(int n, int k)
{
    if (k == 0) return 1;
    int i = 1;
    int base = n;
    while (i < k)
    {
        n *= base;
        i++;
    }
    return n;
}
int ConvertCharArrayToInt(char* lettersCount, int charArrLenght)
{
    bool flag = false;
    int i = 0;
    //checking if the input is a number 
    while (lettersCount[i] != '\0')
    {
        if ((lettersCount[i] - '0') < 0 || (lettersCount[i] - '0') > 39)
        {
            flag = true;
            break;
        }
        i++;
    }
    if (flag)
    {
        return 0;
    }
    i = 0;
    int lettersCnt = 0;
    while (lettersCount[i] != '\0')
    {
        lettersCnt += (lettersCount[i] - '0') * PowerFunction(10, charArrLenght - 1 - i);
        i++;
    }
    return lettersCnt;

}
void ChangeNumOfAvailableLetters(int& availableLettersCount)
{
    cout << "Current available letters per round count: " << availableLettersCount << endl;
    cout << "Insert desired available letters count (between 2 and 100): ";
    char lettersCount[MAX_LETTERS_COUNT_CHAR_ARR] = {'\0'};
    cin.getline(lettersCount, MAX_LETTERS_COUNT_CHAR_ARR);
    int lettersCnt;
    int charArrLenght = GetLenght(lettersCount);
    if (charArrLenght > 3) lettersCnt = 0;
    else lettersCnt = ConvertCharArrayToInt(lettersCount, charArrLenght);
    cout << "-----------------------------------------------" << endl;
    if (lettersCnt >= 2 && lettersCnt <= 100)
    {
        availableLettersCount = lettersCnt;
        cout << "You changed the available letters count per round to " << availableLettersCount << endl;
    }
    else
    {
        cout << "Input must be a number between 2 and 100!" << endl;
    }
    cout << endl;
}
void ChangeNumOfRounds(int& roundsCount)
{
    cout << "Current rounds count: " << roundsCount << endl;
    cout << "Insert desired rounds count (between 1 and 25): ";
    char roundsCntInput[MAX_ROUNDS_COUNT_CHAR_ARR] = {'\0'};
    cin.getline(roundsCntInput, MAX_ROUNDS_COUNT_CHAR_ARR);
    int charArrLenght = GetLenght(roundsCntInput);
    int roundsCnt;
    if (charArrLenght > 2) roundsCnt = 0;
    else roundsCnt = ConvertCharArrayToInt(roundsCntInput, charArrLenght);
    cout << "-----------------------------------------------" << endl;
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
    cout << "-----------------------------------------------" << endl;
    cout << "1. Change number of available letters per round" << endl;
    cout << "2. Change number of rounds" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter your choice: ";
    char choice;
    cin >> choice;
    cin.ignore();
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