#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int swap(const vector<pair<int, int>> paths, int a, int b) {
  
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

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

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);

    total_paths += swap(paths, a-1, b-1);

    cout << total_paths << '\n';
  }

  return 0;
}
