#include <iostream>
using namespace std;

void GenImg(int height){
    // the row that the eye needs to be printed on
    int eye = (height / 2) + 1;

    // print the spaces and asterisks
    for (int i = 1; i <= height; i++){
        // print leading spaces to center the pyramid
        for (int j = 0; j < height - i; j++){
            cout << " ";
        }

        // print the asterisks and watch for the eye row
        for (int k = 1; k <= (i * 2) - 1; k++){
            if (i == eye){
                // if the height level is the one with the eye, calculate positions for <O>
                // if it is one left from the center, print <
                int center = (i * 2 - 1) / 2 + 1;
                if (k == center - 1){
                    cout << "<";
                }
                // if it is the center position, print O
                else if (k == center){
                    cout << "0";
                }
                // if it is one right from the center, print >
                else if (k == center + 1){
                    cout << ">";
                }
                // only even spots in the row will have a space
                else if (k % 2 == 0){
                    cout << " ";
                }
                // every odd space in the row will have an asterisk
                else {
                    cout << "*";
                }
            }
            // for the non-eye row, don't have to worry about positions
            else {
                // if the row is not the one with an eye, add a space
                if (k % 2 == 0){
                    cout << " ";
                }
                // print asterisks in between spaces
                else {
                    cout << "*";
                }
            }
        }
        // move to the next height level 
        cout << endl;
    }

}

// run the function
int main() {
    int height;
    cin >> height;
    GenImg(height);
    return 0;
}
