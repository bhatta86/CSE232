#include <iostream>

// Purpose is to split every item into two equal pieces
// Returns the number given, divided by 2
double SplitInHalf(double a){
    return a / 2;
}

int main() {
    std::cout << SplitInHalf(10) << std::endl;
    return 0;
}