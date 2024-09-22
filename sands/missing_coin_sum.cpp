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

  long long missing = 1;

  for (int i = 0; i < n; i++) {
    if (nums[i] > missing) {
      break;
    }

    missing += nums[i];
  }

  cout << missing << '\n';

  return 0;
}
