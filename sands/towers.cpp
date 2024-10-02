#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  multiset<int> towers;

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);

    auto it = towers.upper_bound(num);

    if (it != towers.end()) {
      towers.erase(it);
    }

    towers.insert(num);
  }
  
  cout << towers.size() << '\n';

  return 0;
}
