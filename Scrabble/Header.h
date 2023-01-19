#pragma once

const int CURRENT_AVAILABLE_LETTERS_ARR_SIZE = 100;
const int MAX_WORD_LENGHT = 100;
void Exit();
int PowerFunction();
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