#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ans = -1;

// 10진수 k를 4진법으로 변환 but 뒤집지는 않음
vector<int> gen(int k) {
    vector<int> a(10);
    for (int i=0; i<10; i++) {
        a[i] = (k&3);
        k >>= 2;
    }
    return a;
}

// 유효한 방향인지 -> 같은 방향 or 반대 방향이면 false
bool valid(vector<int> &dir) {
    int l = dir.size();
    for (int i=0; i+1<l; i++) {
        if (dir[i] == 0 && dir[i+1] == 1) return false;
        if (dir[i] == 1 && dir[i+1] == 0) return false;
        if (dir[i] == 2 && dir[i+1] == 3) return false;
        if (dir[i] == 3 && dir[i+1] == 2) return false;
        if (dir[i] == dir[i+1]) return false;
    }
    return true;
}

void solve(vector<vector<int> > &arr, int cnt, vector<int> dirs, pair<int, int> red, pair<int, int> blue) {
    if(cnt > 10) return;
    if(arr[blue.first][blue.second] == 1) return;
    if(arr[red.first][red.second] == 1) {
        if(ans == -1 || cnt < ans) ans = cnt;
        return;
    }

    // 구슬 이동
    pair<int, int> newred = red;
    pair<int, int> newblue = blue;
    int dir = dirs[cnt];
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
        solve(arr, cnt+1, dirs, newred, newblue);
        solve(arr, cnt+1, dirs, newred, newblue);
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
        solve(arr, cnt+1, dirs, newred, newblue);
        solve(arr, cnt+1, dirs, newred, newblue);
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
        solve(arr, cnt+1, dirs, newred, newblue);
        solve(arr, cnt+1, dirs, newred, newblue);
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
        solve(arr, cnt+1, dirs, newred, newblue);
        solve(arr, cnt+1, dirs, newred, newblue);
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

    for(int i = 0; i < (1 << 10*2); i ++) {
        vector<int> dir = gen(i);
        if (!valid(dir)) continue;
        solve(arr, 0, dir, red, blue);
    }

    cout << ans << '\n';

    return 0;
}