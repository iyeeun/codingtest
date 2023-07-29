#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<int> snakes(101, -1);
    vector<int> ladders(101, -1);

    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        ladders[a] = b;
    }
    for(int i = 0; i < m; i ++) {
        cin >> a >> b;
        snakes[a] = b;
    }

    vector<int> dist(101, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()) {
        int fr = q.front();
        q.pop();

        int next = 0;

        for(int i = 1; i <= 6; i ++) {
            if(fr+i > 100) continue;
            int next = fr+i;
            if(ladders[next] != -1) next = ladders[next];
            else if(snakes[next] != -1) next = snakes[next];
            if(dist[next] == -1) {
                q.push(next);
                dist[next] = dist[fr] + 1;
            }
        }
    }

    cout << dist[100] << endl;

    return 0;
}