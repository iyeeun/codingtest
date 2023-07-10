#include <iostream>
#include <vector>

using namespace std;

int ans = -1;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isFall(pair<int, int> coin, int n, int m) {
    if(coin.first < 0 || coin.first >= n || coin.second < 0 || coin.second >= m) {
        return true;
    }
    return false;
}

void solve(vector<vector<int> > &arr, int cnt, pair<int, int> coin1, pair<int, int> coin2) {

    int n = arr.size();
    int m = arr[0].size();

    if(isFall(coin1, n, m) && isFall(coin2, n, m)) {
        return;
    } else if(isFall(coin1, n, m) || isFall(coin2, n, m)) {
        if(ans == -1 || ans > cnt) ans = cnt;
        return;
    }

    if(cnt >= 10) return;

    for(int i = 0; i < 4; i ++) {
        int newx = coin1.first + dx[i];
        int newy = coin1.second + dy[i];
        bool up1 = false;
        bool up2 = false;
        if(isFall(make_pair(newx, newy), n, m) || arr[newx][newy] == 0) {
            coin1.first = newx;
            coin1.second = newy;
            up1 = true;
        }
        newx = coin2.first + dx[i];
        newy = coin2.second + dy[i];
        if(isFall(make_pair(newx, newy), n, m) || arr[newx][newy] == 0) {
            coin2.first = newx;
            coin2.second = newy;
            up2 = true;
        }

        solve(arr, cnt+1, coin1, coin2);
        
        if(up1) {
            coin1.first -= dx[i];
            coin1.second -= dy[i];
        }
        if(up2) {
            coin2.first -= dx[i];
            coin2.second -= dy[i];
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    char c;
    vector<vector<int> > arr(n, vector<int>(m));
    pair<int, int> coin1;
    coin1.first = -1;
    pair<int, int> coin2;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> c;
            if(c == '#') {
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
                if(c == 'o') {
                    if (coin1.first == -1) {
                        coin1.first = i;
                        coin1.second = j;
                    } else {
                        coin2.first = i;
                        coin2.second = j;
                    }
                }
            }
        }
    }

    solve(arr, 0, coin1, coin2);

    cout << ans << "\n";

    return 0;
}