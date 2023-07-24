#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

using namespace std;

int main() {

  int t, l;
  cin >> t;

  for(int c = 0; c < t; c ++) {
    pair<int, int> s, e;
    cin >> l >> s.first >> s.second >> e.first >> e.second;

    vector<vector<int>> dist(l, vector<int>(l, -1));
    dist[s.first][s.second] = 0;

    queue<pair<int, int>> q;
    q.push(s);

    while(!q.empty()) {
      auto f = q.front();
      q.pop();
      int fdist = dist[f.first][f.second];

      for(int i = 0; i < 8; i ++) {
        if(f.first + dy[i] >= 0 && f.first + dy[i] < l 
        && f.second + dx[i] >= 0 && f.second + dx[i] < l
        && dist[f.first+dy[i]][f.second+dx[i]] == -1) {
          q.push(make_pair(f.first+dy[i], f.second+dx[i]));
          dist[f.first+dy[i]][f.second+dx[i]] = fdist + 1;
          if(f.first+dy[i] == e.first && f.second+dx[i] == e.second) break;
        }
      }
    }

    cout << dist[e.first][e.second] << "\n";

    
  }
  

  return 0;
}