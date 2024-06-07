#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Converts location arithmetic string to an integer
// Calculate distance by powers of 2
// Character distance from "a" is the power
int LocToDec(string const & loc){
    string loc_arith{loc};
    int calculate{0};
    // Loop that calculates power of 2
    for(int i = 0; i < static_cast<int>(loc_arith.length()); i++){
        char letter = loc_arith.at(i);
        int power = int(letter - 'a');
        int total{1};
        for(int j = 0; j < power; j++){
            total *= 2;
        }
        // Add each power to the total
        calculate += total;
    }
    return calculate;
}

// Takes a location string and reduces it to its abbreviated form
// A pair of letters can be turned into the single letter after it
// Ex: cc = d, dd = e, ee = f, etc...
string Abbreviate(string const & loc_arith) {
    string locarith{loc_arith};
    string abbreviated{""};
    bool changed_string = true;

    // while loop covers continuation case such as where abbc --> acc --> ad
    while (changed_string == true){
        changed_string = false;
        abbreviated.clear();

        // sort the string before abbreviating
        sort(locarith.begin(), locarith.end());

        for(int i = 0; i < static_cast<int>(locarith.length()); i++){
            char letter = locarith.at(i);
            // first check to make sure we are not at the end of the string
            // then check to see if the letter is the same as the next one
            if (i < static_cast<int>(locarith.length()) - 1 && letter == locarith.at(i+1)){
                // abbreviate the pair into the next letter, add to the new string
                letter += 1;
                abbreviated += letter;
                i++;
                changed_string = true;
            } 
            else {
                // if the letters are not a pair, just add it back to the new string
                abbreviated += letter;
            }
        }
        // update the current string to work in the next iteration
        locarith = abbreviated; 
    }
    return abbreviated;
}

// Converts an integer to an abbreviated location string
string DecToLoc(int dec){
    string to_abbr{""};
    int i{0};
    // since a = 1 in location arithmetic, we can just add as many a's as dec is equal to
    while (i < dec){
        to_abbr += 'a';
        ++i;
    }
    string abbr = Abbreviate(to_abbr);
    return abbr;
}

// Takes two location strings, adds them, and returns the integer result
int AddLoc(string const & loc1, string const & loc2){
    string locarith1{loc1};
    string locarith2{loc2};

    int num1 = LocToDec(locarith1);
    int num2 = LocToDec(locarith2);

    return num1 + num2;
}

int main(){
    string locstring0{""};
    string locstring1{""};
    string locstring2{""};
    int integer{0};

    cout << "Give me a location string:" << endl;
    cin >> locstring0;

    cout << "Give me an integer:" << endl;
    cin >> integer;

    int integer1 = LocToDec(locstring0);
    cout << locstring0 << " to dec: " << integer1 << endl;

    string abbreviated = Abbreviate(locstring0);
    cout << locstring0 << " abbreviated: " << abbreviated << endl;

    string toloc = DecToLoc(integer);
    cout << integer << " to loc: " << toloc << endl;

    cout << "Give me two more location strings:" << endl;
    cin >> locstring1 >> locstring2;

    int sum = AddLoc(locstring1, locstring2);
    cout << "Sum of " << locstring1 << " and " << locstring2 << " is: " << sum << endl;
}