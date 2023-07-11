#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

int n;
vector<vector<bool> > arr;
vector<bool> col;
vector<bool> digrt;
vector<bool> diglt;

void solve(int cur) {

    if(cur == n) {
        ans ++;
        return;
    }

    for(int i = 0; i < n; i ++) {
        if(!col[i] && !digrt[cur+i] && !diglt[cur-i+n-1]) {
            col[i] = true;
            digrt[cur+i] = true;
            diglt[cur-i+n-1] = true;
            arr[cur][i] = true;
            solve(cur+1);
            col[i] = false;
            digrt[cur+i] = false;
            diglt[cur-i+n-1] = false;
            arr[cur][i] = false;
        }
    }

}

int main() {
    cin >> n;

    arr.assign(n, vector<bool>(n, false));
    col.assign(n, false);
    digrt.assign(2*n-1, false);
    diglt.assign(2*n-1, false);

    solve(0);

    cout << ans << "\n";

    return 0;
}