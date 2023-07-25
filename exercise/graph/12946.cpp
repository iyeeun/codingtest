#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0};

void dfs(vector<vector<int> > &arr, int x, int y, int color) {
    arr[x][y] = color;
    ans = max(ans, 1);

    int n = arr.size();

    for(int i = 0; i < 6; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(arr[nx][ny] != -1) {
                if (arr[nx][ny] == 0) {
                    dfs(arr, nx, ny, -color);
                }
                ans = max(ans, 2);
                if (arr[nx][ny] == color) {
                    ans = max(ans, 3);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    char c;

    vector<vector<int> > arr(n, vector<int>(n));

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> c;
            if(c == '-') arr[i][j] = -1;
            else if(c == 'X') arr[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(arr[i][j] == 0) {
                dfs(arr, i, j, 1);
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}