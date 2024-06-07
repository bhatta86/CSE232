#include <iostream>
using namespace std;

// Function to compute average of two given decimal grades
double ComputeAverage(double grade1, double grade2){
    return (grade1 + grade2) / 2;
}

int main(){
    // Initialize variables for all six words to be inputted
    string blank1{""};
    string blank2{""};
    int as1{0};
    int as2{0};
    double grade1{0.0};
    double grade2{0.0};

    // Input variables for Assignment 1 and its grade
    cin >> blank1;
    cin >> as1;
    cin >> grade1;

    // Input variables for Assignment 2 and its grade
    cin >> blank2;
    cin >> as2;
    cin >> grade2;

    // Utilize ComputeAverage and print output
    double result = ComputeAverage(grade1, grade2);
    cout << "The average of your " << blank1 << " " <<  as1 << " and " 
    << blank2 << " " <<  as2 << " grades is " << result;

    return 0;
}