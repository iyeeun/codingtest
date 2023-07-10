#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int cur, vector<bool> &visit, vector<vector<int> > &adj, vector<int> &res) {
    visit[cur] = true;
    res.push_back(cur); 
    for(int i = 0; i < adj[cur].size(); i ++) {
        int next = adj[cur][i];
        if(!visit[next]) {
            dfs(next, visit, adj, res);
        }
    }
}

int main() {
    int n, m, v, a, b;
    cin >> n >> m >> v;

    vector<bool> visit(n+1, false);
    queue<int> q;
    vector<int> dfsres;
    vector<vector<int> > adjacent(n+1);

    for(int i = 0; i < m; i ++) {
        cin >> a >> b;

        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    for(int i = 1; i <= n; i ++) {
        sort(adjacent[i].begin(), adjacent[i].end(), less<int>());
    }

    dfs(v, visit, adjacent, dfsres);

    for(auto i : dfsres) {
        cout << i << " ";
    }
    cout << "\n";

    fill(visit.begin(), visit.end(), false);
    visit[v] = true;
    q.push(v);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i = 0; i < adjacent[x].size(); i ++) {
            int y = adjacent[x][i];
            if(!visit[y]) {
                visit[y] = true;
                q.push(y);
            }
        }
    }
    cout << "\n";

    return 0;
}