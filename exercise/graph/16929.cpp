#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool dfs(vector<vector<int> > &arr, int x, int y, int prevx, int prevy, int target) {

    if(arr[x][y] == -target) return true;
    arr[x][y] *= -1;

    for(int i = 0; i < 4; i ++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr[0].size()) {
            if((arr[nx][ny] == target || arr[nx][ny] == -target) && !(nx == prevx && ny == prevy)) {
                if(dfs(arr, nx, ny, x, y, target)) return true;
            }
        }
    }
    
    return false;

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n);
    string str;
    for(int i = 0; i < n; i ++) {
        cin >> str;
        for(char c : str) arr[i].push_back(c-'A'+1);
    }

    bool ok = false;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(arr[i][j] < 0) continue;
            bool res = dfs(arr, i, j, -1, -1, arr[i][j]);
            if(res) {
                ok = true;
                break;
            }
        }
    }

    if(ok) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}