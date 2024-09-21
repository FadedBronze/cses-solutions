#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<pair<int, int>> movies;

  for (int i = 0; i < n; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    movies.push_back({start, end});
  }

  sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
  });

  int last = -1;
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (movies[i].first >= last) {
      last = movies[i].second;
      count += 1;
    }
  }

  cout << count << '\n';

  return 0;
} 
