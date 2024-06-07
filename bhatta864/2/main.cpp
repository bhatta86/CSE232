#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;


// PROBLEM DESCRIPTION
/*  Generates obfuscated texts by only reversing the middle of words 
    Read stdIO a sequence whitespace separated by lower-case only 
    words. 
    Program should output 8 words per line separated by spaces.
    A scrambled word has its first and last letters unchanged
    Use a void function ScrambleWord that takes in a string
*/ 

void ScrambleWord(string sequence){
    // Initialize the beginning variables
    vector<string> words; 
    vector<string> scrambled;
    string word{""};
    string first_letter{""};
    string last_letter{""};

    // Reads through the long input string and separates words between whitespace
    // Adds each word as its own element in the words vector
    for (char letter : sequence){
        if (letter != ' '){
            word.push_back(letter);
        }
        else{
            words.push_back(word);
            word.clear();
        }
    }
    
    // go through each word in the vector of all the words
    for (string SingleWord : words){
        // if a word has less than three letters, it cannot be scrambled, so just put it as is
        if (SingleWord.length() <= 3){
            scrambled.push_back(SingleWord);
            continue;
        }
        // otherwise, the word will need to be scrambled as such
        // take the first and last letter and store them for later use
        // with just the middle letters, reverse the order
        // create a new word string, add the first, middle reversed, then last letters
        // add this new word to the new vector of words. 
        else{
            first_letter = SingleWord.at(0);
            last_letter = SingleWord.at(SingleWord.length() - 1);

            string middle_letters = SingleWord.substr(1, SingleWord.length() - 2);

            // this only needs to iterate through len / 2 so we don't reverse it twice
            int len = middle_letters.length();
            for (int i = 0; i < len / 2; i++){
                char tempFirst = middle_letters.at(i);
                middle_letters.at(i) = middle_letters.at(len - i - 1);
                middle_letters.at(len - i - 1) = tempFirst;
            }

            // create the new obfuscated word
            string newWord = first_letter + middle_letters + last_letter;
            scrambled.push_back(newWord);
        }
    }
    
    // output each word in the new word list, and everytime it's at 8, make a newline
    int line{0};
    for (string oneword : scrambled){
        if (line == 8){
            cout << endl;
            line = 0;
        }
        cout << oneword << " ";
        line++;
    }

}

int main(){
    string input_sentence;
    // read input until the end of the file, including whitespace. 
    getline(cin, input_sentence);
    input_sentence.push_back(' ');
    ScrambleWord(input_sentence);    
}
