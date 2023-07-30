#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, srcx, srcy, dstx, dsty;
    cin >> n >> srcx >> srcy >> dstx >> dsty;

    int dx[] = {-2, -2, 0, 0, 2, 2};
    int dy[] = {-1, 1, -2, 2, -1, 1};

    vector<vector<int> > arr(n, vector<int>(n, -1));

    queue<pair<int, int> > q;
    q.push(make_pair(srcx, srcy));
    arr[srcx][srcy] = 0;

    while(!q.empty()) {
        auto f = q.front();
        q.pop();

        for(int i = 0; i < 6; i ++) {
            int nx = f.first + dx[i];
            int ny = f.second + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == -1) {
                arr[nx][ny] = arr[f.first][f.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << arr[dstx][dsty] << endl;

    return 0;
}