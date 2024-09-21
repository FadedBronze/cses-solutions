#include <algorithm>
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

int main() { 
  int n;
  scanf("%d", &n);

  vector<tuple<int, int>> events;

  for (int i = 0; i < n; i++) {
    int start, end;
    scanf("%d %d", &start, &end);

    events.push_back({start, 1});
    events.push_back({end, -1});
  }

  sort(events.begin(), events.end());

  int max_val = 0;
  int count = 0;

  for (int i = 0; i < n*2; i++) {
    count += get<1>(events[i]);

    if (count > max_val) {
      max_val = count;
    }
  }

  cout << max_val << '\n';

  return 0;
}
