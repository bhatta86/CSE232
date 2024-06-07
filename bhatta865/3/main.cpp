#include "wordle.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    string secretWord{""};

    cout << "Give me a secret word: ";
    cin >> secretWord;

    GameHost(secretWord);
    return 0;
}