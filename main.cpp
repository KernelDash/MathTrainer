#include <iostream>
#include <random>
#include <string>

using u32    = uint_least32_t; 
using engine = std::mt19937;

void clear() {
    std::cout << "\033[2J\033[1;1H";
}

int main(void) {
  std::string userInput;

  std::random_device os_seed;
  const u32 seed = os_seed();

  engine generator(seed);
  std::uniform_int_distribution< u32 > distribute(1, 9);

  clear();
  std::cout << "Math Trainer. \n Press 'q' to quit." << std::endl;

  // Main loop
  while (userInput != "q") {
    int firstNum = distribute(generator);
    int secondNum = distribute(generator);
    int result = firstNum + secondNum;

    std::cout << firstNum << " + " << secondNum << " = ";
    std::cin >> userInput;

    clear();

    if (stoi(userInput) != result)
      std::cout << "\033[7;31mWrong. Right answer: " << result << "\033[0m" << std::endl;
    else
      std::cout << "\033[7;32mCorrect!\033[0m" << std::endl;
  }

  return 0;
}

// std::cout << distribute(generator) << std::endl;
