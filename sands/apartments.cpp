#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> space_sep_nums(string str) {
  vector<int> nums;

  string acc = "";

  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];

    if (ch == ' ') {
      nums.push_back(atoi(acc.c_str()));
      acc = ' ';
    } else {
       acc += ch;
    }
  }

  nums.push_back(atoi(acc.c_str()));
  acc = ' ';

  return nums;
}

int main() {
  string l1;
  getline(cin, l1);
  
  string l2;
  getline(cin, l2);
  
  string l3;
  getline(cin, l3);

  int max_diff = space_sep_nums(l1)[2];
  vector<int> people = space_sep_nums(l2);
  vector<int> apartments = space_sep_nums(l3);

  int pairs = 0;

  sort(people.begin(), people.end());
  sort(apartments.begin(), apartments.end());

  int i = 0;
  int j = 0;

  while (i < people.size() && j < apartments.size()) {
    int diff = people[i] - apartments[j];

    if (diff > max_diff) {
      j++;
    } else if (diff < -max_diff) {
      i++; 
    } else {
      pairs += 1;
      i++;
      j++;
    }
  }

  cout << pairs;

  return 0;
}
