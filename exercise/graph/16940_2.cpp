#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > adj(n+1);
    vector<int> inp(n);
    vector<int> order(n+1);
    vector<bool> visit(n+1, false);
    
    int a, b;
    for(int i = 0; i < n-1; i ++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i ++) {
        cin >> inp[i];
        order[inp[i]] = i; // 들어온 순서를 저장함
    }

    // 들어온 순서로 인접 리스트를 정렬함
    for(int i = 1; i <= n; i ++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }

    bool ans = true;
    queue<int> q;
    q.push(1);
    int idx = 0;

    while(!q.empty()) {
        int fr = q.front();
        q.pop();

        if(fr != inp[idx]) {
            ans = false;
            break;
        }

        visit[fr] = true;

        for(int next : adj[fr]) {
            if(!visit[next]) {
                q.push(next);
            }
        }
        idx ++;
    }

    if(ans) cout << "1\n";
    else cout << "0\n";

    return 0;
}