#ifndef WORDLE_H
#define WORDLE_H
#include <string>

std::string WordleResponse(const std::string & secretWord, const std::string & guessWord);
void GameHost(const std::string & secretWord);

#endif