#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  string str;
  vector<vector<int>> arr(n, vector<int>(m));
  vector<vector<bool>> visit(n, vector<bool>(m, false));
  vector<vector<int>> dist(n, vector<int>(m, 0));
  queue<int> q;

  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      arr[i][j] = str[j] - '0';
    }
  }

  dist[0][0] = 1;
  q.push(0);
  visit[0][0] = true;
  while (!q.empty()) {
    int x = q.front();
    int xx = x / m;
    int xy = x % m;
    int xdist = dist[xx][xy];

    q.pop();

    if (xx != 0 && !visit[xx - 1][xy] && arr[xx - 1][xy] == 1) {
      dist[xx - 1][xy] = xdist + 1;
      visit[xx - 1][xy] = true;
      q.push(x - m);
    }
    if (xx != n - 1 && !visit[xx + 1][xy] && arr[xx + 1][xy] == 1) {
      dist[xx + 1][xy] = xdist + 1;
      visit[xx + 1][xy] = true;
      q.push(x + m);
    }
    if (xy != 0 && !visit[xx][xy - 1] && arr[xx][xy - 1] == 1) {
      dist[xx][xy - 1] = xdist + 1;
      visit[xx][xy - 1] = true;
      q.push(x - 1);
    }
    if (xy != m - 1 && !visit[xx][xy + 1] && arr[xx][xy + 1] == 1) {
      dist[xx][xy + 1] = xdist + 1;
      visit[xx][xy + 1] = true;
      q.push(x + 1);
    }
  }
  
  cout << dist[n - 1][m - 1] << endl;

  return 0;
}