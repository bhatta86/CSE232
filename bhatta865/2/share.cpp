#include "share.h"
#include <string>
#include <iostream>
#include <vector>

/* This is the implementation file. The function has already been declared in share.h, but it has not been defined to do anything.
   This is where the function definition is created, and we can program it to do what it is supposed to do. */

std::string SharedLetters(const std::string & string1, const std::string string2, const std::string * string3) {
    // Get the largest string as iteration limit
    int loopLength{};
    int size1 = (string1.size());
    int size2 = (string2.size());
    int size3 = (*string3).size();
    if (size3 > size2 && size3 > size1){
        loopLength = size3;
    }
    else if(size2 > size3 &&  size2 > size1){
        loopLength = size2;
    }
    else{
        loopLength = size1;
    }

    // initialize a string that holds the return value, as well as chars for each letter comparison
    std::string return_String; 
    char char1{};
    char char2{};
    char char3{};
    // if the program attempts to access past a word's length, make it a null character for comparison
    for (int i = 0; i < loopLength; i++){
        if (i < static_cast<int>(string1.size())){
            char1 = string1.at(i);
        }else{
            char1 = '\0';
        }
        if (i < static_cast<int>(string2.size())){
            char2 = string2.at(i);
        }else{
            char2 = '\0';
        }
        if (i < static_cast<int>((*string3).size())){
            char3 = (*string3).at(i);
        }else{
            char3 = '\0';
        }

        // if characters are null, their comparison is not valid, otherwise, it is valid
        // it can only be 0, 1 or 3, since it goes by pairs of words. 
        if ((char1 == '\0' && char2 == '\0') || (char2 == '\0' && char3 == '\0') || (char1 == '\0' && char3 == '\0')) {
            return_String += "0,";
        }
        else if (char1 == char2 && char2 == char3){
            return_String += "3,";
        }
        else if (char1 == char2 || char2 == char3 || char1 == char3){
            return_String += "1,";
        }
        else{
            return_String += "0,";
        }

    }
    return return_String;
}
