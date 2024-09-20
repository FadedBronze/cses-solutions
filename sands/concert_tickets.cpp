#include <set>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  multiset<int> prices;
  
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    int price;
    scanf("%d", &price);
    prices.insert(price);
  }
  
  for (int i = 0; i < m; i++) {
    int person;
    scanf("%d", &person);

    auto ub = prices.upper_bound(person);

    if (ub == prices.begin()) {
      cout << "-1\n";
    } else {
      ub--;
      cout << *ub << "\n";
      prices.erase(prices.lower_bound(*ub));
    }
  }

  return 0;
}
