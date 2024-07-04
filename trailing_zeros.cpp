#include <iostream>
#include <string>

int main() {
  std::string line_1;
  std::getline(std::cin, line_1, '\n');

  int n = std::stoi(line_1);
  int zeros = 0;
  
  for (int i = 5; i < n + 1; i += 5) {
      int num = i;

      do {
          num /= 5;
          zeros += 1;
      } while (num % 5 == 0);
  }

  std::cout << zeros << "\n";
}

