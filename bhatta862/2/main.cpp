#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

// Function given for random number generator
int RandNumGen() {
  std::uniform_int_distribution<> rng(1, 3);
  return rng(gen);
}

int main() {
  // Print user choice options
  std::cout << "Enter 1 (Rock), 2 (Paper), or 3 (Scissors): ";

  // Initialize variables for each choice
  int comp_choice = RandNumGen();
  int human_choice{0};

  // Take user input
  std::cin >> human_choice;

  // Print user game choice
  if (human_choice == 1)
    std::cout << "You picked: Rock\n";
  if (human_choice == 2)
    std::cout << "You picked: Paper\n";
  if (human_choice == 3)
    std::cout << "You picked: Scissors\n";

  // Print computer game choice
  if (comp_choice == 1)
    std::cout << "The computer picked: Rock\n";
  if (comp_choice == 2)
    std::cout << "The computer picked: Paper\n";
  if (comp_choice == 3)
    std::cout << "The computer picked: Scissors\n";

  // Print results based on each choice
  // "else if" learned from (https://www.w3schools.com/cpp/cpp_conditions_elseif.asp)
  if (human_choice == comp_choice) {
    std::cout << "It's a draw!" << std::endl;
  } else if (human_choice == 1 && comp_choice == 3) {
    std::cout << "You win!" << std::endl;
  } else if (human_choice == 2 && comp_choice == 1) {
    std::cout << "You win!" << std::endl;
  } else if (human_choice == 3 && comp_choice == 2) {
    std::cout << "You win!" << std::endl;
  } else if (comp_choice == 1 && human_choice == 3) {
    std::cout << "You lose!" << std::endl;
  } else if (comp_choice == 2 && human_choice == 1) {
    std::cout << "You lose!" << std::endl;
  } else if (comp_choice == 3 && human_choice == 2) {
    std::cout << "You lose!" << std::endl;
  }

  return 0;
}
