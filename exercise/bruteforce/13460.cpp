#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans = -1;

void solve(vector<vector<int> > &arr, int cnt, int dir, pair<int, int> red, pair<int, int> blue) {
    if(cnt > 10) return;
    if(arr[blue.first][blue.second] == 1) return;
    if(arr[red.first][red.second] == 1) {
        if(ans == -1 || cnt < ans) ans = cnt;
        return;
    }

    // 구슬 이동
    pair<int, int> newred = red;
    pair<int, int> newblue = blue;
    if(dir == 0) { // left
        while(true) {
            if(arr[newred.first][newred.second-1] == -1) {
                break;
            } else if(arr[newred.first][newred.second-1] == 0) {
                newred.second --;
            } else if(arr[newred.first][newred.second-1] == 1) {
                newred.second --;
                break;
            }
        }
        while(true) {
            if(arr[newblue.first][newblue.second-1] == -1) {
                break;
            } else if(arr[newblue.first][newblue.second-1] == 0) {
                newblue.second --;
            } else if(arr[newblue.first][newblue.second-1] == 1) {
                newblue.second --;
                break;
            }
        }
        if(newred == newblue && arr[newred.first][newred.second] != 1) {
            if(red.second < blue.second) newblue.second ++;
            else newred.second ++;
        }
        solve(arr, cnt+1, 2, newred, newblue);
        solve(arr, cnt+1, 3, newred, newblue);
    } else if(dir == 1) { // right
        while(true) {
            if(arr[newred.first][newred.second+1] == -1) {
                break;
            } else if(arr[newred.first][newred.second+1] == 0) {
                newred.second ++;
            } else if(arr[newred.first][newred.second+1] == 1) {
                newred.second ++;
                break;
            }
        }
        while(true) {
            if(arr[newblue.first][newblue.second+1] == -1) {
                break;
            } else if(arr[newblue.first][newblue.second+1] == 0) {
                newblue.second ++;
            } else if(arr[newblue.first][newblue.second+1] == 1) {
                newblue.second ++;
                break;
            }
        }
        if(newred == newblue && arr[newred.first][newred.second] != 1) {
            if(red.second < blue.second) newred.second --;
            else newblue.second --;
        }
        solve(arr, cnt+1, 2, newred, newblue);
        solve(arr, cnt+1, 3, newred, newblue);
    } else if(dir == 2) { // up
        while(true) {
            if(arr[newred.first-1][newred.second] == -1) {
                break;
            } else if(arr[newred.first-1][newred.second] == 0) {
                newred.first --;
            } else if(arr[newred.first-1][newred.second] == 1) {
                newred.first --;
                break;
            }
        }
        while(true) {
            if(arr[newblue.first-1][newblue.second] == -1) {
                break;
            } else if(arr[newblue.first-1][newblue.second] == 0) {
                newblue.first --;
            } else if(arr[newblue.first-1][newblue.second] == 1) {
                newblue.first --;
                break;
            }
        }
        if(newred == newblue && arr[newred.first][newred.second] != 1) {
            if(red.first < blue.first) newblue.first ++;
            else newred.first ++;
        }
        solve(arr, cnt+1, 0, newred, newblue);
        solve(arr, cnt+1, 1, newred, newblue);
    } else if(dir == 3) { // down
        while(true) {
            if(arr[newred.first+1][newred.second] == -1) {
                break;
            } else if(arr[newred.first+1][newred.second] == 0) {
                newred.first ++;
            } else if(arr[newred.first+1][newred.second] == 1) {
                newred.first ++;
                break;
            }
        }
        while(true) {
            if(arr[newblue.first+1][newblue.second] == -1) {
                break;
            } else if(arr[newblue.first+1][newblue.second] == 0) {
                newblue.first ++;
            } else if(arr[newblue.first+1][newblue.second] == 1) {
                newblue.first ++;
                break;
            }
        }
        if(newred == newblue && arr[newred.first][newred.second] != 1) {
            if(red.first < blue.first) newred.first --;
            else newblue.first --;
        }
        solve(arr, cnt+1, 0, newred, newblue);
        solve(arr, cnt+1, 1, newred, newblue);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    vector<vector<int> > arr(n);
    pair<int, int> red;
    pair<int, int> blue;
    for(int i = 0; i < n; i ++) {
        cin >> s;
        for(int j = 0; j < m; j ++) {
            char c = s[j];
            if(c == '#') arr[i].push_back(-1);
            else if(c == '.') arr[i].push_back(0);
            else if(c == 'O') arr[i].push_back(1);
            else if(c == 'R') {
                arr[i].push_back(0);
                red.first = i;
                red.second = j;
            } else if(c == 'B') {
                arr[i].push_back(0);
                blue.first = i;
                blue.second = j;
            }
        }
    }

    for(int i = 0; i < 4; i ++) {
        solve(arr, 0, i, red, blue);
    }

    cout << ans << '\n';

    return 0;
}