#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> nums;
  set<int> heard;

  for (int i = 0; i < n; i++) {
    int song;
    scanf("%d", &song);
    nums.push_back(song);
  }

  int i = 0;
  int j = 0;
  int max_heard = 0;

  while (i < n && j < n) {
    while (j < n && !heard.count(nums[j])) {
      heard.insert(nums[j]);
      max_heard = max(max_heard, j - i + 1);
      j++;
    }

    while (j < n && heard.count(nums[j])) {
      heard.erase(nums[i]);
      i++;
    }
  }

  cout << max_heard << '\n';

  return 0;
}
