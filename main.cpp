#include <algorithm>
#include <iostream>
#include <random>
#include <string>

using u32    = uint_least32_t; 
using engine = std::mt19937;

// Ansi escape codes
constexpr auto RED    = "\033[7;31m";
constexpr auto GREEN  = "\033[7;32m";
constexpr auto RESET  = "\033[0m";

void clear() {
  std::cout << "\033[2J\033[1;1H"; // Clear terminal
}

int main(void) {
  std::string userInput;
  int difficulty;

  // Random generator setup
  std::random_device os_seed;
  const u32 seed = os_seed();
  engine generator(seed);
  std::uniform_int_distribution<u32> distribute;

  clear();
  std::cout << "Math Trainer. (Press 'q' to quit)" << '\n';

  // Get difficulty and set number range
  std::cout << "1 = Single digit numbers\n2 = Double digit numbers\n3 = Triple digit numbers\nEnter the difficulty: ";
  std::cin >> difficulty;
  switch (difficulty) {
    case 1: distribute = std::uniform_int_distribution<u32>(1, 9); break;
    case 2: distribute = std::uniform_int_distribution<u32>(1, 99); break;
    case 3: distribute = std::uniform_int_distribution<u32>(1, 999); break;
    default:
      std::cout << RED << "Invalid difficulty" << RESET << '\n';
      exit(0);
  }

  clear();

  // Main loop
  while (true) {
    // Generate random numbers
    int firstNum = distribute(generator);
    int secondNum = distribute(generator);
    int result = firstNum + secondNum;

    std::cout << firstNum << " + " << secondNum << " = ";
    std::cin >> userInput;

    clear();

    if (userInput == "q") {
      std::cout << "Bye!\n";
      break;
    }
    // Check if input is numeric
    if (!all_of(userInput.begin(), userInput.end(), isdigit)) {
      std::cout << RED << "Invalid input" << RESET << '\n';
      continue;
    }    
    if (stoi(userInput) == result)
      std::cout << GREEN << "Correct!" << RESET << '\n';
    else
      std::cout << RED << "Wrong. Right answer: " << result << RESET << '\n';
  }
  return 0;
}
