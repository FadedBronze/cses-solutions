#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<pair<int, int>> paths;

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    paths.push_back({num, i});
  }

  sort(paths.begin(), paths.end(), [](pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
  });

  int total_paths = 1;

  for (int i = 1; i < n; i++) {
    if (paths[i].second < paths[i-1].second) {
      total_paths++;
    }
  }

  cout << total_paths << '\n';

  return 0;
}
