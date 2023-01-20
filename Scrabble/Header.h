#pragma once

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
* <header file>
*
*/
const int CURRENT_AVAILABLE_LETTERS_ARR_SIZE = 100;
const int MAX_WORD_LENGHT = 100;
void Exit();
int PowerFunction(int n, int k);
void ChangeNumOfAvailableLetters(int& availableLettersCount);
void ChangeNumOfRounds(int& roundsCount);
void Settings(int& roundsCount, int& availableLettersCount);
int GetLenght(char* charArray);
bool FindWord(char* currentWord, char* charArr);
bool DoesWordConsistOfAvailableLettersOnly(const char* availableLetters, char* word, int& availableLettersCount);
void MakeWordAllCaps(char* currentWord);
void GenerateLetters(int lettersPerRound, char* currentAvailableLetters);
bool IsWordValid(char* currentWord);
void AddNewWord();
void NewGame(int& rounds, int& lettersPerRound);