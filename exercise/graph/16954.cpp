#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    char c;
    bool ok = false;
    vector<vector<int> > board(8, vector<int>(8, 0));
    for(int i = 0; i < 8; i ++) {
        for(int j = 0; j < 8; j ++) {
            cin >> c;
            if(c == '#') {
                board[i][j] = -1;
            }
        }
    }

    int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    vector<vector<vector<bool> > > visit(8, vector<vector<bool> >(8, vector<bool>(9, false)));
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(7, 0, 0));
    visit[7][0][0] = true;

    while(!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        if(x == 0 && y == 7) {
            ok = true;
            break;
        }

        for(int i = 0; i < 9; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

            if(z > 7) z = 7;

            if(nx-z >= 0 && board[nx-z][ny] == -1) continue;
            if(nx-z-1 >= 0 && board[nx-z-1][ny] == -1) continue;
            if(!visit[nx][ny][z+1]) {
                visit[nx][ny][z+1] = true;
                q.push(make_tuple(nx, ny, z+1));
            }
        }

    }

    if(ok) cout << "1\n";
    else cout << "0\n";

    return 0;
}