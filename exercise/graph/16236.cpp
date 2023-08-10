#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;



pair<pair<int, int>, int> bfs(vector<vector<int> > &board, set<pair<int, int> > &eat, pair<int, int> &shark, int size) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int n = board.size();
    vector<vector<int> > dist(n, vector<int>(n, -1));
    queue<pair<int, int> > q;

    q.push(shark);
    dist[shark.first][shark.second] = 0;
    while(!q.empty()) {
        auto fr = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = fr.first + dx[i];
            int ny = fr.second + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1 && board[nx][ny] <= size) {
                dist[nx][ny] = dist[fr.first][fr.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    vector<pair<int, int> > eattmp(eat.begin(), eat.end());
    for(int i = eattmp.size()-1; i >= 0; i --) {
        if(dist[eattmp[i].first][eattmp[i].second] == -1) {
            eattmp.erase(eattmp.begin() + i);
        }
    }

    sort(eattmp.begin(), eattmp.end(), [&dist](pair<int, int> a, pair<int, int> b) {
        if(dist[a.first][a.second] == dist[b.first][b.second]) {
            if(a.first == b.first) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        } else {
            return dist[a.first][a.second] < dist[b.first][b.second];
        }
    });
    
    if(eattmp.empty()) {
        return make_pair(make_pair(-1, -1), -1);
    }

    return make_pair(eattmp[0], dist[eattmp[0].first][eattmp[0].second]);
}

int main() {
    int n;
    cin >> n;
    pair<int, int> shark;
    vector<vector<int> > board(n, vector<int>(n));
    set<pair<int, int> > eat;
    int ans = 0;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark.first = i;
                shark.second = j;
                board[i][j] = 0;
            } else if(board[i][j] == 1) {
                eat.insert(make_pair(i, j));
            }
        }
    }
    
    int size = 2;
    int cnt = 0;
    while(eat.size() > 0) {
        auto ate = bfs(board, eat, shark, size);
        if(ate.second == -1) break;
        ans += ate.second;
        board[ate.first.first][ate.first.second] = 0;
        shark = ate.first;
        eat.erase(ate.first);

        cnt ++;
        if(cnt == size) {
            size ++;
            cnt = 0;
        }
        
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(board[i][j] > 0 && size > board[i][j]) {
                    eat.insert(make_pair(i, j));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}