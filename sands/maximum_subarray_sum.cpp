#include <iostream>
#include <limits.h>
#include <vector>

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

  long long best = LONG_LONG_MIN;
  long long past = 0;

  for (int i = 0; i < n; i++) {
    if (past > 0) {
      past += nums[i];
    } else {
      past = nums[i];
    }

    if (past > best) {
      best = past;
    }
  }

  cout << best << '\n';

  return 0;
}
