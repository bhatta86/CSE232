#ifndef SHARE_H // checks if share_h has been defined yet
#define SHARE_H // checks to see if this header has been included
#include <string>

/*  Header files are used to declare the interfaces of functions and classes. 
    They keep the implementation of the code separate from the definition. 
    The compiler can check for consistency in function declarations     */

// declare the shared letter functions
// this is not where the function is created, only the declaration
std::string SharedLetters(const std::string & string1, const std::string string2, const std::string * string3);

// end if function is defined. 
#endif 