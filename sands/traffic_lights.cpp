#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, x;
  scanf("%d %d", &x, &n);

  map<int, int> sects;
  sects.insert({x, x});

  multiset<int> sizes;
  sizes.insert(x);

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);

    auto it = sects.upper_bound(num);
    
    if (it != sects.end()) {
      int start = it->first - it->second;
      int last = it->first;
      
      sects.erase(it);
      sizes.erase(sizes.lower_bound(it->second));

      //num to start
      sects.insert({num, num - start});
      sizes.insert(num - start);
      
      //end to num
      sects.insert({last, last - num});
      sizes.insert(last - num);

      cout << *sizes.rbegin() << '\n';
    }
  }

  return 0;
}
