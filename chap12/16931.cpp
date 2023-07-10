#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;

    vector<vector<int> > arr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            ans += 2; // upper & lower face
            // front
            if(i == n-1) ans += arr[i][j];
            else ans += max(arr[i][j] - arr[i+1][j], 0);
            // back
            if(i == 0) ans += arr[i][j];
            else ans += max(arr[i][j] - arr[i-1][j], 0);
            // left
            if(j == 0) ans += arr[i][j];
            else ans += max(arr[i][j] - arr[i][j-1], 0);
            // right
            if(j == m-1) ans += arr[i][j];
            else ans += max(arr[i][j] - arr[i][j+1], 0);
        }
    }

    cout << ans << "\n";

    return 0;
}