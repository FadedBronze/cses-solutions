#include <iostream>
#include <string>

int main() {
  std::string line_1;
  std::getline(std::cin, line_1, '\n');

  int n = std::stoi(line_1);
  int nn = n * n;

  int total_possible = 0;
  
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      int possible_spaces = nn - (y * n + x) - 1;

      bool vspace2 = y + 2 < n;
      bool vspace1 = vspace2 || y + 1 < n;
      bool vspacen2 = false;
      bool vspacen1 = false;
      
      bool hspace2 = x + 2 < n;
      bool hspace1 = hspace2 || x + 1 < n;
      bool hspacen2 = x - 2 >= 0;
      bool hspacen1 = hspacen2 || x - 1 >= 0;

      if (vspace2) {
        if (hspace1) 
          possible_spaces--;
        if (hspacen1) 
          possible_spaces--;
      }

      if (vspacen2) {
        if (hspace1) 
          possible_spaces--;
        if (hspacen1) 
          possible_spaces--;
      }

      if (hspace2) {
        if (vspace1) 
          possible_spaces--;
        if (vspacen1) 
          possible_spaces--;
      }

      if (hspacen2) {
        if (vspace1) 
          possible_spaces--;
        if (vspacen1) 
          possible_spaces--;
      }

      total_possible += possible_spaces;
    }
  }

  std::cout << total_possible << '\n';
}
