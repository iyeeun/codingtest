#include <iostream>
#include <vector>

using namespace std;

void dfs(int idx, vector<vector<int> > &adj, vector<bool> &visit) {
  visit[idx] = true;

  for(int i = 0; i < adj[idx].size(); i ++) {
    int next = adj[idx][i];
    if(!visit[next]) {
      dfs(next, adj, visit);
    }
  }
}

int main() {

  int n, m, a, b;
  int ans = 0;
  cin >> n >> m;

  vector<vector<int> > adj(n+1);
  vector<bool> visit(n+1, false);

  for(int i = 0; i < m; i ++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i ++) {
    if(!visit[i]) {
      ans ++;
      dfs(i, adj, visit);
    }
  }

  cout << ans << endl;

  return 0;
}