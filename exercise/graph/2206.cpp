#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int ans = -1;

void findDist(vector<vector<int> > arr) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    arr[0][0] = -1;

    while(!q.empty()) {
        pair<int, int> fr = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = fr.first + dx[i];
            int ny = fr.second + dy[i];

            if(nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr[0].size() && arr[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                arr[nx][ny] = arr[fr.first][fr.second] - 1;
            }
        }
    }

    int res = -arr[arr.size()-1][arr[0].size()-1];
    if(res != 0 && (ans == -1 || res < ans)) ans = res;
}

int main() {
    int n, m;
    cin >> n >> m;
    string str;

    vector<vector<int> > arr(n, vector<int>(m));

    for(int i = 0; i < n; i ++) {
        cin >> str;
        for(int j = 0; j < m; j ++) {
            arr[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] == 1) {
                arr[i][j] = 0;
                findDist(arr);
                arr[i][j] = 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}