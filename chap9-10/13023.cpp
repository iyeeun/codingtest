#include <iostream>
#include <vector>

using namespace std;

int ans = false;

void dfs(int idx, vector<bool> &isvisited, vector<vector<int> > &adj, int depth) {    
    if(depth == 4) {
        ans = true;
        return;
    }

    if(ans) return;

    isvisited[idx] = true;
    for(int i = 0; i < adj[idx].size(); i ++) {
        if(!isvisited[adj[idx][i]]) {
            dfs(adj[idx][i], isvisited, adj, depth+1);
        }
    }
    isvisited[idx] = false;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<bool> isvisited(n, false);
    vector<vector<int> > adjacent(n);

    for(int i = 0; i < m; i ++) {
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    for(int i = 0; i < n; i ++) {
        fill(isvisited.begin(), isvisited.end(), false);
        dfs(i, isvisited, adjacent, 0);
        if(ans) break;
    }

    cout << ((ans)? 1 : 0) << "\n";

    return 0;
}