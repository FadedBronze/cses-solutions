#include <map>
#include <iostream>

using namespace std;

int main() {
  int n;
  int target;
  scanf("%d %d", &n, &target);
  map<int, int> diffs;
  bool success = false;

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    diffs.insert({target - num, i});
    
    auto found = diffs.find(num);

    if (found != diffs.end() && found->second != i) {
      cout << found->second+1 << " " << i+1 << '\n';
      success = true;
      break;
    }
  }

  if (!success) {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}
