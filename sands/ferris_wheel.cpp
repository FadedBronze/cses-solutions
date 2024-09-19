#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> space_sep_nums(string str) {
  vector<long long> nums;

  string acc = "";

  for (long long i = 0; i < str.size(); i++) {
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
  string l2;
  getline(cin, l1);
  getline(cin, l2);

  long long max_weight = space_sep_nums(l1)[1];
  vector<long long> people = space_sep_nums(l2);

  sort(people.rbegin(), people.rend());

  long long i = 0LL;
  long long j = people.size() - 1;
  long long pairs = 0LL;

  while (j > i) {
    long long sum = people[i] + people[j];
   
    i++;

    if (sum > max_weight) {
      continue;
    }

    pairs++;
    j--;
  }

  cout << people.size() - pairs << '\n';

  return 0;
}
