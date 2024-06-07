#include "wordle.h"
#include <iostream>
#include <string>
#include <vector>

// function that checks if letters are correct or in the word. 
std::string WordleResponse(const std::string & secretWord, const std::string & guessWord){
    std::string output{"....."}; // start with a fully hidden output that can be changed as we go on
    bool matchLetters[5]{false}; // an array that has 5 spots to check if each letter has been matched

    // first, check if the letters are in the right position, since this is the higher precedence case
    for (int i = 0; i < 5; i++){
        if (guessWord.at(i) == secretWord.at(i)){ // if the letters match
            output.at(i) = guessWord.at(i); // set the output string to have that letter visible
            matchLetters[i] = true; // set that place holder in the array true so we know it's guessed
        }
    }

    // secondly, check if there are any correct letters that are not in the right positions
    for (int j = 0; j < 5; j++){
        if (output.at(j) == '.'){ // only process these characters if they are unmatched
            for (int k = 0; k < 5; k++){
                // if the guessed word has a letter that is anywhere within the secret word, then mark it as '?'
                if (guessWord.at(j) == secretWord.at(k) && matchLetters[j] != true){
                    output.at(j) = '?';
                    matchLetters[j] = true; // set its position to true so we don't match it again
                    break;
                }
            }
        }
    }
    return output;
}

/* I didn't want to put all the input/output within the main.cpp, or within the WordleResponse function, so
   I figured it would be useful to create a GameHost function, which carries out the process of running the game. */
void GameHost(const std::string & secretWord){
    const int maxAttempts{6};
    std::string guess{""};

    // count the user attempts, and prompt for inputs
    for (int attempt = 0; attempt < maxAttempts; attempt++){
        std::cout << "Give me a guess: ";

        std::cin >> guess;

        // if the user inputs a ctrl d, they forfeit the game, and lost. 
        if (std::cin.eof()){
            std::cout << "\nYou Lose." << std::endl; 
            return;
        }

        // each time, use WordleResponse to check the word the user inputs. 
        std::string response = WordleResponse(secretWord, guess);
        std::cout << response << std::endl;

        // if the response from WordleResponse equals the secret word, the user wins. 
        if (response == secretWord){
            std::cout << "You Win!" << std::endl;
            return;
        }
    }
    // if the for loop ends, or if the return statement from line 58 is not used, the player loses. 
    std::cout << "You Lose." << std::endl;
}

