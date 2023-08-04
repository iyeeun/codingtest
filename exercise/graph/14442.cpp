#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > arr(n, vector<int>(m));
    char c;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    vector<vector<vector<int> > > info(n, vector<vector<int> > (m, vector<int>(k+1, -1)));
    info[0][0][0] = 1;
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()) {
        int x, y, r;
        tie(x, y, r) = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 0 && info[nx][ny][r] == -1) {
                    info[nx][ny][r] = info[x][y][r] + 1;
                    q.push(make_tuple(nx, ny, r));
                } else if(arr[nx][ny] == 1 && r <= k && info[nx][ny][r+1] == -1) {
                    info[nx][ny][r+1] = info[x][y][r] + 1;
                    q.push(make_tuple(nx, ny, r+1));
                }
            }
        }
    }

    int ans = -1;
    for(int i = 0; i <= k; i ++) {
        if(info[n-1][m-1][i] != -1 && (ans == -1 || ans > info[n-1][m-1][i])) ans = info[n-1][m-1][i];
    }
    cout << ans << endl;

    return 0;
}