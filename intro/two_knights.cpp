#include <iostream>
#include <string>

int main() {
  std::string line_1;
  std::getline(std::cin, line_1, '\n');
  long long n = std::stoi(line_1);

  for (long long i = 1; i < n+1; i++) {
    long long result = (((i*i) * (i*i-1) / 2) - 2 * ((i-1) * (i-2)) - 2 * ((i-1) * (i-2)));
    std::cout << result << std::endl; 
  }
}
