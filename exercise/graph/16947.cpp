#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(vector<int> &visit, vector<vector<int> > &adj, int station, int prev) {
    // 사이클이 존재한다면 어디서부터 어디까지인지 알아야 함 -> 리턴값 이용
    // -2 : 사이클을 찾았지만 포함되지 않는 노드, -1 : 사이클을 찾지 못함, 0 이상 : 사이클의 시작 인덱스

    // 1. 종료 조건 : 이미 방문한 노드를 방문함 -> 사이클 존재
    if(visit[station] == 1) return station;

    // 2. 노드 방문 처리
    visit[station] = 1;

    // 3. 다음 호출 : 인접한 노드가 이전에 방문한 노드가 아니고 갈 수 있는 조건을 만족할 때, 다음을 호출
    for(int next : adj[station]) {
        // 이전에 방문한 노드는 무시
        if(next == prev) continue;
        // 다음 노드의 결과에 따라 리턴 달라짐
        int res = dfs(visit, adj, next, station);
        // 다음 노드가 -2 -> 사이클을 찾았지만 해당 노드는 아님
        if(res == -2) return -2;
        // 다음 노드가 0 이상 -> 시작 인덱스
        if(res >= 0) {
            // 사이클에 포함시키고
            visit[station] = 2;
            // 내가 같은 거면 끝까지 돌아온 것 -> 그 이후로는 포함되지 않도록 함
            if(station == res) return -2;
            else return res;
        }
    }
    return -1;
}

int main() {
    int n, a, b;
    cin >> n;
    vector<vector<int> > adj(n);
    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> visit(n, false);
    vector<int> dist(n, 0);
    dfs(visit, adj, 0, -1);
    queue<int> q;
    
    for(int i = 0;i < visit.size(); i ++) {
        if(visit[i] != 2) {
            dist[i] = -1;
        } else {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int fr = q.front();
        q.pop();

        for(int ad : adj[fr]) {
            if(dist[ad] == -1) {
                q.push(ad);
                dist[ad] = dist[fr] + 1;
            }
        }
    }

    for(int i : dist) {
        cout << i << " ";
    }

    return 0;
}