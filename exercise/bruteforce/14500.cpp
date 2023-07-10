#include <iostream>
#include <vector>

using namespace std;

int maxval = -1;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void solve(vector<vector<int> > &arr, vector<vector<bool> > &visit, int cnt, int curx, int cury, int sum) {
    if(cnt == 4) {
        if(sum > maxval) maxval = sum;
        return;
    }

    if(curx < 0 || curx >= arr.size() || cury < 0 || cury >= arr[0].size()) return;
    if(visit[curx][cury]) return;

    visit[curx][cury] = true;
    for(int i = 0; i < 4; i ++) {        
        solve(arr, visit, cnt+1, curx + dx[i], cury + dy[i], sum+arr[curx][cury]);
    }
    visit[curx][cury] = false;

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr(n, vector<int>(m));
    vector<vector<bool> > visit(n, vector<bool>(m, false));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            solve(arr, visit, 0, i, j, 0);
            if(j+2 < m && i+1 < n) {
                int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
                if(sum > maxval) maxval = sum;
            }
            if(j+1 < m && i-1 >= 0 && i+1 < n) {
                int sum = arr[i][j] + arr[i-1][j+1] + arr[i][j+1] + arr[i+1][j+1];
                if(sum > maxval) maxval = sum;
            }
            if(i-1 >= 0 && j+2 < m) {
                int sum = arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i][j+2];
                if(sum > maxval) maxval = sum;
            }
            if(i+2 < n && j+1 < m) {
                int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
                if(sum > maxval) maxval = sum;
            }
        }
    }
    
    cout << maxval << "\n";

    return 0;
}