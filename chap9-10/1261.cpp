#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  int n, m;
  cin >> n >> m;
  string str;

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  vector<vector<int>> arr(m, vector<int>(n));
  vector<vector<int>> walls(m, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    cin >> str;
    for (int j = 0; j < n; j++) {
      arr[i][j] = str[j] - '0';
    }
  }

  deque<pair<int, int>> d;
  d.push_back(make_pair(0, 0));
  walls[0][0] = 0;

  while (!d.empty()) {
    pair<int, int> f = d.front();
    d.pop_front();

    int fx = f.first;
    int fy = f.second;

    for (int i = 0; i < 4; i++) {
      int nextx = fx + dx[i];
      int nexty = fy + dy[i];
      if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n &&
          walls[nextx][nexty] == -1) {
        if (arr[nextx][nexty] == 0) {
          d.push_front(make_pair(nextx, nexty));
          walls[nextx][nexty] = walls[fx][fy];
        } else {
          d.push_back(make_pair(nextx, nexty));
          walls[nextx][nexty] = walls[fx][fy] + 1;
        }
      }
    }
  }

  cout << walls[m-1][n-1] << "\n";

  return 0;
}