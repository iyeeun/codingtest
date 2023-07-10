#include <iostream>
#include <vector>

using namespace std;

bool ans = true;

void dfs(int idx, vector<vector<int>> &adj, vector<int> &nodes, int type) {

  nodes[idx] = type;
  int newtype = (type == 1)? 2 : 1;

  for(int i = 0; i < adj[idx].size(); i ++) {
    int next = adj[idx][i];
    if(nodes[next] == 0) {
      dfs(next, adj, nodes, newtype);
    } else {
      if(type == nodes[next]) {
        ans = false;
        return;
      }
    }
  }
}

int main() {

  int k, v, e, a, b;
  cin >> k;

  for(int i = 0; i < k; i ++) {
    cin >> v >> e;

    vector<vector<int>> adj(v+1);
    vector<int> nodes(v+1, 0);
    for(int j = 0; j < e; j ++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int type = 1;
    for(int j = 1; j <= v; j ++) {
      if(nodes[j] == 0) {
        dfs(j, adj, nodes, type);
      }
    }

    cout << (ans? "YES" : "NO") << "\n";
    ans = true;
    
  }


  return 0;
}