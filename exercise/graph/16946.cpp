#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    vector<vector<int> > arr(n, vector<int>(m));
    vector<vector<int> > ans(n, vector<int>(m));
    char c;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> c;
            arr[i][j] = c - '0';
            if(arr[i][j] == 1) arr[i][j] = -1;
        }
    }

    vector<vector<bool> > visit(n, vector<bool>(m, false));
    int groupidx = 0;
    vector<int> groupsize;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] == 0 && !visit[i][j]) {
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visit[i][j] = true;
                arr[i][j] = groupidx;
                int cnt = 1;
                while(!q.empty()) {
                    auto fr = q.front();
                    q.pop();

                    for(int t = 0; t < 4; t ++) {
                        int nx = fr.first + dx[t];
                        int ny = fr.second + dy[t];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0 && !visit[nx][ny]) {
                            q.push(make_pair(nx, ny));
                            visit[nx][ny] = true;
                            arr[nx][ny] = groupidx;
                            cnt ++;
                        }
                    }
                }
                groupidx ++;
                groupsize.push_back(cnt);
            }
        }
    }
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] == -1) {
                ans[i][j] = 1;
                set<int> s;
                for(int t = 0; t < 4; t ++) {
                    int nx = i + dx[t];
                    int ny = j + dy[t];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != -1) {
                        s.insert(arr[nx][ny]);
                    }
                }
                for(auto t : s) {
                    ans[i][j] += groupsize[t];
                }
                ans[i][j] %= 10;
            } else {
                ans[i][j] = 0;
            }
        }
    }
    
    for(auto i : ans) {
        for(auto j : i) {
            cout << j;
        }
        cout << "\n";
    }

    return 0;
}