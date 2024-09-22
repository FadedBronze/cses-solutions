#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<long long> nums;

  for (int i = 0; i < n; i++) {
    long long num;
    scanf("%lld", &num);
    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());

  long long median = nums[(n-1)/2];

  long long cost = 0;

  for (int i = 0; i < n; i++) {
    cost += abs(median - nums[i]);
  }

  cout << cost << '\n';

  return 0;
}
