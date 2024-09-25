//Incomplete

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int swap(vector<pair<int, int>> paths, int a, int b) {
  int old = 0;

  if (a > 0 && paths[a - 1].second > paths[a].second) {
    old += 1;
  }
  if (a < paths.size() - 2 && paths[a + 1].second < paths[a].second) {
    old += 1;
  }
  if (b > 0 && paths[b - 1].second > paths[b].second) {
    old += 1;
  }
  if (b < paths.size() - 2 && paths[b + 1].second < paths[b].second) {
    old += 1;
  }

  cout << old << ' ';

  int temp = paths[a].second;
  paths[a].second = paths[b].second;
  paths[b].second = temp;

  int new_ = 0;

  if (a > 0 && paths[a - 1].second > paths[a].second) {
    new_ += 1;
  }
  if (a < paths.size() - 2 && paths[a + 1].second < paths[a].second) {
    new_ += 1;
  }
  if (b > 0 && paths[b - 1].second > paths[b].second) {
    new_ += 1;
  }
  if (b < paths.size() - 2 && paths[b + 1].second < paths[b].second) {
    new_ += 1;
  }
  
  cout << new_ << '\n';

  return new_ - old;
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

    int affinity = swap(paths, a-1, b-1);

    for (int j = 0; j < paths.size(); j++) {
      cout << paths[j].second << ' ';
    }
    cout << '\n';
    
    for (int j = 0; j < paths.size(); j++) {
      cout << paths[j].first << ' ';
    }
    cout << '\n';

    total_paths += affinity;

    cout << affinity << '\n';
    cout << total_paths << '\n';
  }

  return 0;
}
