#include <iostream>
#include <string>

using namespace std;

#define UP x, y + 1
#define DOWN x, y - 1
#define RIGHT x, y + 1
#define LEFT x, y - 1

#define TOPRIGHT x + 1, y + 1
#define TOPLEFT x - 1, y + 1
#define BOTTOMRIGHT x, y + 1
#define BOTTOMLEFT x, y + 1

int solve_grid_paths(int x, int y, int i, string s, bool (*vis)[7]) {
  if (i == 48) {
    if (x == 0 && y == 6) {
      return 1;
    }
    return 0;
  }

  if (x == 0 && y == 6)
    return 0;

  if (vis[x][y])
    return 0;

  vis[x][y] = true;

  char dir = s[i]; 
  int paths = 0;

  cout << dir << "\n";

  if (dir == 'U')
    paths += solve_grid_paths(x, y + 1, i + 1, s, vis);
  else if (dir == 'D')
    paths += solve_grid_paths(x, y - 1, i + 1, s, vis);
  else if (dir == 'R')
    paths += solve_grid_paths(x + 1, y, i + 1, s, vis);
  else if (dir == 'L')
    paths += solve_grid_paths(x - 1, y, i + 1, s, vis);
  else {
    paths += solve_grid_paths(x, y + 1, i + 1, s, vis);
    paths += solve_grid_paths(x, y - 1, i + 1, s, vis);
    paths += solve_grid_paths(x + 1, y, i + 1, s, vis);
    paths += solve_grid_paths(x - 1, y, i + 1, s, vis); 
  }

  vis[x][y] = false;
  return paths;
}

int main() {
  string s;
  getline(cin, s);

  bool vis[7][7] = { 
    {false, false, false, false, false, false, false },  
    {false, false, false, false, false, false, false },  
    {false, false, false, false, false, false, false },  
    {false, false, false, false, false, false, false },  
    {false, false, false, false, false, false, false },  
    {false, false, false, false, false, false, false }, 
    {false, false, false, false, false, false, false }
  };

  int result = solve_grid_paths(0, 0, 0, s, vis); 

  cout << result << "\n";

  return 0;
}
