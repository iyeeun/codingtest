#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int s;
  cin >> s;

  vector<vector<int>> dist(2000, vector<int>(2000, -1));
  queue<pair<int, int>> q;

  q.push(make_pair(1, 0));
  dist[1][0] = 0;

  while(!q.empty()) {
    pair<int, int> p = q.front();
    int smile = p.first;
    int clipboard = p.second;
    int pdist = dist[smile][clipboard];
    q.pop();

    // op1
    if(dist[smile][smile] == -1) {
      q.push(make_pair(smile, smile));
      dist[smile][smile] = pdist + 1;
      if(smile == s) break;
    }

    // op2
    if(smile+clipboard < 2000 && dist[smile+clipboard][clipboard] == -1) {
      q.push(make_pair(smile+clipboard, clipboard));
      dist[smile+clipboard][clipboard] = pdist + 1;
      if(smile+clipboard == s) break;
    }

    // op3
    if(smile != 0 && dist[smile-1][clipboard] == -1) {
      q.push(make_pair(smile-1, clipboard));
      dist[smile-1][clipboard] = pdist + 1;
      if(smile-1 == s) break;
    }
  }

  int ans = 100000000;
  for(auto i : dist[s]) {
    if(i != -1 && ans > i) ans = i;
  }

  cout << ans << "\n";

  return 0;
}