#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// function which will filter words as their neighbors
// At first I made this a pass by reference function, though, as I began to 
// implement the functionality, I figured it would be simpler to just print 
// it out from within the function itself. 
void FilterNeighbors(string &sentence) {
    // take the input string and separate the words into a vector. 
    // similar to a functionality I made for assignment 4 question 2
    vector<string> words;
    string word{""};
    for (char &letter : sentence) {
        if (letter == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += letter;
        }
    }
    // if the word is empty, which probably won't happen, there will be no chars to make a word
    if (!word.empty()) {
        words.push_back(word);
    }

    // filter the string based on its neighbors
    // for each word in the vector
    for (string singleWord : words) {
        string newWord{""};
        int len = singleWord.length();
        // for each letter in the individual word
        for (int i = 0; i < len; i++) {
            // check the first character, since it won't have anything behind it. 
            if (i == 0) {
                // have to check the absolute value, since larger ascii values may result in negatives
                if (len > 1 && abs(singleWord.at(i) - singleWord.at(i + 1)) <= 1) {
                    newWord += singleWord.at(i);
                }
            // check the last character, since there won't be anything after it. 
            } else if (i == len - 1) {
                if (abs(singleWord.at(i) - singleWord.at(i - 1)) <= 1) {
                    newWord += singleWord.at(i);
                }
            // if the character is not first or last, it will have a before and after neighbor
            } else {
                if (abs(singleWord.at(i) - singleWord.at(i - 1)) <= 1 || abs(singleWord.at(i) - singleWord.at(i + 1)) <= 1) {
                    newWord += singleWord.at(i);
                }
            }
        }
        // for each new string that is filtered, print it out before it resets in the next iteration. 
        cout << newWord << endl;
    }
}

int main() {
    string singleLine; 
    string input;

    // read the input from cin until an EOF is found (ctrl + D)
    while (getline(cin, singleLine)) {
        input += singleLine + " ";
    }
    
    FilterNeighbors(input);
    return 0;
}
