#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ans = -1;

int findSafe(vector<vector<int> > arr, int n, int m) {
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(!q.empty()) {
        pair<int, int> fr = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = fr.first + dx[i];
            int ny = fr.second + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                arr[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] == 0) cnt ++;
        }
    }

    return cnt;
}

void makeWall(vector<vector<int> > &arr, int cnt) {
    int n = arr.size();
    int m = arr[0].size();

    if(cnt == 3) {
        int res = findSafe(arr, n, m);
        if(ans == -1 || res > ans) ans = res;
        return;
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] != 0) continue;
            arr[i][j] = -1;
            makeWall(arr, cnt+1);
            arr[i][j] = 0;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> arr[i][j];
        }
    }

    makeWall(arr, 0);

    cout << ans << endl;

    return 0;
}