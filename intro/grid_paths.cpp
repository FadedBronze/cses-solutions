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

bool occupied(int x, int y, bool(*vis)[7][7]) {
  return (*vis)[x][y] or x > 6 or y > 6 or x < 0 or y < 0;
}

bool fork(int x, int y, bool(*vis)[7][7]) {
  return (
    occupied(UP, vis) && occupied(DOWN, vis) && !occupied(LEFT, vis) && !occupied(RIGHT, vis) ||
    !occupied(UP, vis) && !occupied(DOWN, vis) && occupied(LEFT, vis) && occupied(RIGHT, vis)
  );
}

bool corner_fork(int x, int y, bool(*vis)[7][7]) {
  return (
    !occupied(UP, vis) && !occupied(RIGHT, vis) && occupied(TOPRIGHT, vis) ||
    !occupied(UP, vis) && !occupied(LEFT, vis) && occupied(TOPLEFT, vis) ||
    !occupied(DOWN, vis) && !occupied(RIGHT, vis) && occupied(BOTTOMRIGHT, vis) ||
    !occupied(DOWN, vis) && !occupied(LEFT, vis) && occupied(BOTTOMLEFT, vis)
  );
}

//void print_grid(int x, int y, bool(*vis)[7][7]) {
//  for (int i = 0; i < 7; i++) {
//    for (int j = 0; j < 7; j++) {
//      if ((*vis)[i][j]) {
//        cout << "*";
//      } else if (j == y && i == x) {
//        cout << "x";
//      } else {
//        cout << " ";
//      }
//    }
//    cout << "\n";
//  }
//  cout << x << "\n";
//  cout << y << "\n";
//  cout << "grid\n";
//}

int solve(int x, int y, int i, string s, bool(*vis)[7][7]) {
  if (occupied(x, y, vis)) {
    return 0;
  }
  
  if (fork(x, y, vis)) {
    return 0;
  }
  
  if (corner_fork(x, y, vis)) {
    return 0;
  }

  if (x == 0 && y == 0) {
    if (i == 48) {
      return 1;
    }
    return 0;
  }

  (*vis)[x][y] = true;
  
  char dir = s[i];
  int paths = 0;
  
  if (dir == 'U' || dir == '?') {
    paths += solve(UP, i+1, s, vis);
  }
  if (dir == 'D' || dir == '?') {
    paths += solve(DOWN, i+1, s, vis);
  }
  if (dir == 'R' || dir == '?') {
    paths += solve(RIGHT, i+1, s, vis);
  }
  if (dir == 'L' || dir == '?') {
    paths += solve(LEFT, i+1, s, vis);
  } 
  
  (*vis)[x][y] = false;

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

  int paths = solve(0, 6, 0, s, &vis);

  cout << paths << "\n";
}
