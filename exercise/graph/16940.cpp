#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > adj(n+1);
    vector<int> inp(n);
    vector<int> parent(n+1, -1);
    
    int a, b;
    for(int i = 0; i < n-1; i ++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i ++) cin >> inp[i];

    bool ans = true;

    queue<int> q;
    q.push(1);
    parent[1] = 0;
    int idx = 1;
    for(int i = 0; i < n; i ++) {
        if(q.empty()) {
            ans = false;
            break;
        }
        int f = q.front();
        q.pop();

        if(f != inp[i]) {
            ans = false;
            break;
        }

        int cnt = 0;
        for(int next : adj[f]) {
            if(parent[next] == -1) {
                parent[next] = f;
                cnt ++;
            }
        }

        for(int j = 0; j < cnt; j ++) {
            if(idx+j >= n || parent[inp[idx+j]] != f) {
                ans = false;
                break;
            } else {
                q.push(inp[idx+j]);
            }
        }
        idx += cnt;
    }

    if(ans) cout << "1\n";
    else cout << "0\n";

    return 0;
}