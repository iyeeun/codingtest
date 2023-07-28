#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ans = false;

void dfs(vector<bool> &visit, vector<vector<int> > &adj, vector<int> &res, vector<int> &inp, int cur) {

    if(res.size() == inp.size()) {
        if(res == inp) ans = true;
        return;
    }

    if(visit[cur]) return;

    visit[cur] = true;
    res.push_back(cur);
    
    for(int next : adj[cur]) {
        dfs(visit, adj, res, inp, next);
    }
}

int main() {
    int n, a, b;
    cin >> n;

    vector<vector<int> > adj(n+1);
    for(int i = 0; i < n-1; i ++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> inp(n);
    vector<int> order(n+1);
    for(int i = 0; i < n; i ++) {
        cin >> inp[i];
        order[inp[i]] = i;
    }

    for(int i = 1; i <= n; i ++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &a, const int &b){
            return order[a] < order[b];
        });
    }

    vector<bool> visit(n+1, false);
    vector<int> res;

    dfs(visit, adj, res, inp, 1);

    if(ans) cout << "1\n";
    else cout << "0\n";

    return 0;
}