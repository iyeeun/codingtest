#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

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

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(2, 0)));
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 1;

    while(!q.empty()) {
        int fx, fy, fz;
        tie(fx, fy, fz) = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 0) {
                    if(dist[nx][ny][fz] == 0) {
                        q.push(make_tuple(nx, ny, fz));
                        dist[nx][ny][fz] = dist[fx][fy][fz] + 1;
                    }
                } else {
                    if(fz == 0 && arr[nx][ny] == 1 && dist[nx][ny][1] == 0) {
                        q.push(make_tuple(nx, ny, 1));
                        dist[nx][ny][1] = dist[fx][fy][fz] + 1;
                    }
                }  
            }
        }
    }

    if(dist[n-1][m-1][0] != 0 && dist[n-1][m-1][1] != 0) {
        cout << ((dist[n-1][m-1][0] > dist[n-1][m-1][1])? dist[n-1][m-1][1] : dist[n-1][m-1][0]) << endl;
    } else if(dist[n-1][m-1][0] != 0) {
        cout << dist[n-1][m-1][0] << endl;
    } else if(dist[n-1][m-1][1] != 0) {
        cout << dist[n-1][m-1][1] << endl;
    } else {
        cout << "-1\n";
    }

    return 0;
}