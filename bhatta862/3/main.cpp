#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ValidateConfig(int config) {
    // Initialize the vector
    std::vector<int> digits;

    // Add the digits in the config integer into the vector
    // Method to slice digits from an integer into a vector was learned from (https://stackoverflow.com/questions/4889974/how-to-convert-int-to-vectorint)
    /* Using modulus 10 will allow us to retrieve the last number of the integer, since it will 
        be the remainder. Then, dividing by 10 will remove the remainder since this is an int
        and not a double. We can then repeat this process to get all the digits in the vector. */
    while (config > 0) {
        digits.push_back(config % 10);
        config /= 10;
    }

    // Check if the length of the vector is less than 9 so we can add leading zeros
    while (digits.size() < 9) {
        digits.push_back(0);
    }
    
    // The first while loop creates a backwards vector, so it must be reversed
    // Iterate start upward, and end downwards, make the start = end and repeat for each value
    int start = 0;
    int end = digits.size() - 1;
    while (start < end){
        int current = digits.at(start);
        digits.at(start) = digits.at(end);
        digits.at(end) = current;
        start++;
        end--;
    }

    // See how many X's and O's there are to calculate an impossible game
    // The case in which a game is invalid is when X > O + 1 or O > X + 1
    int x_count{0};
    int o_count{0};
    for (int i : digits){
        if (i == 1) ++x_count;
        if (i == 0) ++o_count;
    }

    // Check if the game is invalid
    if (x_count > o_count + 1 || o_count > x_count + 1) {
        return "Invalid configuration!";
    } 

    // Check for winning board configurations
    /* Board positions can be represented as such:
        P0 P1 P2
        P3 P4 P5
        P6 P7 P8 */

    // Draw: All cells are filled, no blanks
    int empty_cells{0};
    for (int digit : digits){
        if (digit == 2) ++empty_cells;
    }
    if (empty_cells == 0) {
        return "It's a draw!";
    }

    // Horizontal Wins: (0, 1, 2), (3, 4, 5), (6, 7, 8)
    if ((digits[0] == digits[1] && digits[0] == digits[2] && digits[0] != 2) || 
        (digits[3] == digits[4] && digits[3] == digits[5] && digits[3] != 2) ||
        (digits[6] == digits[7] && digits[6] == digits[8] && digits[6] != 2)){
            if (digits[0] == 1 || digits[1] == 1 || digits[2] == 1) return "X wins!";
            else return "O wins!";
        }

    // Vertical Wins: (0, 3, 6), (1, 4, 7), (2, 5, 8)
    if ((digits[0] == digits[3] && digits[0] == digits[6] && digits[0] != 2) ||
        (digits[1] == digits[4] && digits[1] == digits[7] && digits[1] != 2) || 
        (digits[2] == digits[5] && digits[2] == digits[8] && digits[2] != 2)){
            if (digits[0] == 1 || digits[3] == 1 || digits[6] == 1) return "X wins!";
            else return "O wins!";
        }

    // Diagonal Wins: (0, 4, 8), (6, 4, 2)
    if ((digits[0] == digits[4] && digits[0] == digits[8] && digits[0] != 2) || 
        (digits[6] == digits[4] && digits[6] == digits[2] && digits[6] != 2)){
            if (digits[0] == 1 || digits[6] == 1) return "X wins!";
            else return "O wins!";
        }

    /*  I received the error: "control reaches end of non-void function", to which I found that this 
        error occurs when there is a possibility that the function can end with no return statement. 
        To fix this, adding this final return here stops the error, though, there should be no case in 
        this program where this return statement will ever actually be returned. */
    return "";
}

int main(){
    int config{0};
    cout << "Enter configuration: ";
    cin >> config;
    cout << "Result: " << ValidateConfig(config) << endl;
    return 0;
}