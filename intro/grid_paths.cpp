#include <iostream>
#include <string>

using namespace std;

#define UP x, y + 1
#define DOWN x, y - 1
#define RIGHT x + 1, y
#define LEFT x - 1, y

#define TOPRIGHT x + 1, y + 1
#define TOPLEFT x - 1, y + 1
#define BOTTOMRIGHT x + 1, y - 1
#define BOTTOMLEFT x - 1, y - 1

bool occupied(int x, int y, bool(&vis)[7][7]) {
  return vis[x][y] || x > 6 || y > 6 || x < 0 || y < 0;
}

bool occupied_raw(int x, int y, bool(&vis)[7][7]) {
  return vis[x][y] || x > 6 || y > 6 || x < 0 || y < 0;
}

int solve(int x, int y, int i, string s, bool(&vis)[7][7]) { 
  bool up = occupied(UP, vis); 
  bool down = occupied(DOWN, vis); 
  bool right = occupied(RIGHT, vis); 
  bool left = occupied(LEFT, vis); 

  if (
    (up && down && !left && !right) ||
    (!up && !down && left && right) ||

    !up && !right && occupied_raw(TOPRIGHT, vis) ||
    !up && !left && occupied_raw(TOPLEFT, vis) ||
    !down && !right && occupied_raw(BOTTOMRIGHT, vis) ||
    !down && !left && occupied_raw(BOTTOMLEFT, vis)
  ) {
    return 0;
  }

  if (x == 0 && y == 0) {
    if (i == 48) {
      return 1;
    }
    return 0;
  }

  vis[x][y] = true;
  
  char dir = s[i];
  int paths = 0;

  switch (dir) {
    case 'U':
      if (!up)
        paths += solve(UP, i+1, s, vis);
      break;
    case 'D': 
      if (!down)
        paths += solve(DOWN, i+1, s, vis);
      break;
    case 'R': 
      if (!right)
        paths += solve(RIGHT, i+1, s, vis);
      break;
    case 'L': 
      if (!left)
        paths += solve(LEFT, i+1, s, vis);
      break;
    case '?':
      if (!up)
        paths += solve(UP, i+1, s, vis);
      if (!down)
        paths += solve(DOWN, i+1, s, vis);
      if (!right)
        paths += solve(RIGHT, i+1, s, vis);
      if (!left)
        paths += solve(LEFT, i+1, s, vis);
  }
   
  vis[x][y] = false;

  return paths;
}

int main() {
  bool vis[7][7] = {
    {false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false},
    {false, false, false, false, false, false, false},
  };

  string s;
  getline(cin, s);

  int paths = solve(0, 6, 0, s, vis);

  cout << paths << "\n";
}
