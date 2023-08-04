#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int arr[1000][1000][11][2];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool> > isWall(n, vector<bool>(m));
    char c;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> c;
            if(c == '1') isWall[i][j] = true;
            else isWall[i][j] = false;
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    // vector<vector<vector<vector<int> > > > arr(n, vector<vector<vector<int> > >(m, vector<vector<int> >(k+1, vector<int>(2, -1))));
    arr[0][0][0][0] = 1; // 0 : day, 1 : night
    queue<tuple<int, int, int, int> > q;
    q.push(make_tuple(0, 0, 0, 0));
    while(!q.empty()) {
        int x, y, r, t;
        tie(x, y, r, t) = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(!isWall[nx][ny] && arr[nx][ny][r][1-t] == 0) {
                    arr[nx][ny][r][1-t] = arr[x][y][r][t] + 1;
                    q.push(make_tuple(nx, ny, r, 1-t));
                } else if(isWall[nx][ny] && r+1 <= k && t == 0 && arr[nx][ny][r+1][1] == 0) {
                    arr[nx][ny][r+1][1] = arr[x][y][r][t] + 1;
                    q.push(make_tuple(nx, ny, r+1, 1));
                }
            }
        }

        if(t == 1 && arr[x][y][r][1-t] == 0) {
            arr[x][y][r][1-t] = arr[x][y][r][t] + 1;
            q.push(make_tuple(x, y, r, 1-t));
        }
    }

    int ans = -1;
    for(int i = 0; i <= k; i ++) {
        for(int j = 0; j < 2; j ++) {
            int num = arr[n-1][m-1][i][j];
            if(num != 0 && (ans == -1 || ans > num)) ans = num;
        }
    }
    cout << ans << endl;

    return 0;
}