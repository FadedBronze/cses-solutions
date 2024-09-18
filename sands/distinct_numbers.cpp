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

  auto nums = space_sep_nums(l2);

  sort(nums.begin(), nums.end());

  int count = 0;
  int last = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (i == 0 || nums[i] != last) {
      count += 1;
    }

    last = nums[i];
  }

  cout << count;

  return 0;
}
