#include <iostream>

using namespace std;

int n, m, k;
int nums[10][10];
bool chosen[10][10];
long ans = -100000000;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void find_max(int prev, int cnt, int sum) {
    if(cnt == k) {
        if(sum > ans) ans = sum;
        return;
    }

    for(int i = prev+1; i < n*m; i ++) {
        int x = i / m;
        int y = i % m;
        if(chosen[x][y]) continue;
        bool ok = true;
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (chosen[nx][ny]) ok = false;
            }
        }

        if(ok) {
            chosen[x][y] = true;
            find_max(x*m+y, cnt+1, sum+nums[x][y]);
            chosen[x][y] = false;
        }
    }
}

int main() {

    cin >> n >> m >> k;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> nums[i][j];
        }
    }

    find_max(-1, 0, 0);

    cout << ans << endl;

    return 0;
}