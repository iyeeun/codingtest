#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(vector<vector<int>> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (arr[i][j] == 0)
        return false;
    }
  }
  return true;
}

int main() {

  int n, m;
  cin >> m >> n;

  vector<vector<int>> tomato(n, vector<int>(m));
  vector<vector<int>> dist(n, vector<int>(m));
  vector<vector<bool>> visit(n, vector<bool>(m, false));
  vector<pair<int, int>> starts;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tomato[i][j];
      if (tomato[i][j] == 1)
        starts.push_back(make_pair(i, j));
    }
  }

  if (valid(tomato)) {
    cout << "0\n";
    return 0;
  }

  queue<pair<int, int>> q;
  for (auto i : starts) {
    visit[i.first][i.second] = true;
    q.push(i);
    dist[i.first][i.second] = 0;
  }

  while (!q.empty()) {
    auto f = q.front();
    int fdist = dist[f.first][f.second];
    q.pop();

    if (f.first != 0 && tomato[f.first - 1][f.second] == 0 &&
        !visit[f.first - 1][f.second]) {
      q.push(make_pair(f.first - 1, f.second));
      visit[f.first - 1][f.second] = true;
      tomato[f.first - 1][f.second] = 1;
      dist[f.first - 1][f.second] = fdist + 1;
    }
    if (f.first != n - 1 && tomato[f.first + 1][f.second] == 0 &&
        !visit[f.first + 1][f.second]) {
      q.push(make_pair(f.first + 1, f.second));
      visit[f.first + 1][f.second] = true;
      tomato[f.first + 1][f.second] = 1;
      dist[f.first + 1][f.second] = fdist + 1;
    }
    if (f.second != 0 && tomato[f.first][f.second - 1] == 0 &&
        !visit[f.first][f.second - 1]) {
      q.push(make_pair(f.first, f.second - 1));
      visit[f.first][f.second - 1] = true;
      tomato[f.first][f.second - 1] = 1;
      dist[f.first][f.second - 1] = fdist + 1;
    }
    if (f.second != m - 1 && tomato[f.first][f.second + 1] == 0 &&
        !visit[f.first][f.second + 1]) {
      q.push(make_pair(f.first, f.second + 1));
      visit[f.first][f.second + 1] = true;
      tomato[f.first][f.second + 1] = 1;
      dist[f.first][f.second + 1] = fdist + 1;
    }
  }
  
  if (valid(tomato)) {
    int ans = 0;
    for(auto d : dist) {
      int tmp = *max_element(d.begin(), d.end());
      if(tmp > ans) ans = tmp;
    }
    cout << ans << "\n";
  } else {
    cout << "-1\n";
  }

  return 0;
}