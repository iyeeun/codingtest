#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, m, x, y, k, cmd;
  cin >> n >> m >> x >> y >> k;

  vector<vector<int>> map(n, vector<int>(m));
  vector<int> dice(6, 0); // bottom : 0

  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> map[i][j];
    }
  }

  for(int i = 0; i < k; i ++) {
    cin >> cmd;
    if(cmd == 1) {
      if(y+1 == m) continue;
      int tmp = dice[0];
      dice[0] = dice[5];
      dice[5] = dice[2];
      dice[2] = dice[4];
      dice[4] = tmp;
      y ++;
    } else if(cmd == 2) {
      if(y == 0) continue;
      int tmp = dice[0];
      dice[0] = dice[4];
      dice[4] = dice[2];
      dice[2] = dice[5];
      dice[5] = tmp;
      y --;
    } else if(cmd == 3) {
      if(x == 0) continue;
      int tmp = dice[0];
      dice[0] = dice[3];
      dice[3] = dice[2];
      dice[2] = dice[1];
      dice[1] = tmp;
      x --;
    } else if(cmd == 4) {
      if(x+1 == n) continue;
      int tmp = dice[0];
      dice[0] = dice[1];
      dice[1] = dice[2];
      dice[2] = dice[3];
      dice[3] = tmp;
      x ++;
    }
    if(map[x][y] == 0) {
        map[x][y] = dice[0];
      } else {
        dice[0] = map[x][y];
        map[x][y] = 0;
      }
    cout << dice[2] << '\n';
  }

  return 0;
}