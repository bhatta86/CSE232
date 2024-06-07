#include "share.h" // included with "..." since it is in the same directory
#include <iostream>
#include <string>
using namespace std; // this is the only place to use a namespace, or else it will get cluttered. 

// now with the use of implementation/header files, the only thing that needs to be in main.cpp is the main function. 
int main() {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    cout << SharedLetters(str1, str2, &str3); // since string3 is a pointer, it must take in a reference, or else no value. 
}
