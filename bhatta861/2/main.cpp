#include <iostream>
using namespace std;

// Function to compute the sum of two given numbers
// To make it incorrect, there is always 1 added to second_num
int ComputeSum(int first_num, int second_num){
    return first_num + ++second_num;
}

int main(){
    // Define the variables we are taking input for
    int first{0};
    int second{0};

    // Print question and input first number
    cout << "Enter first number: ";
    cin >> first;

    // Print question and input second number
    cout << "Enter second number: ";
    cin >> second;

    // Store sum in final variable, print output
    int final = ComputeSum(first, second);
    cout << "Your sum: " << final << endl;

    return 0;
}
