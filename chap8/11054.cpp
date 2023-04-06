#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    
    vector<vector<int> > dp(n, vector<int>(2, 0));

    dp[0][0] = 1;
    dp[n-1][1] = 1;

    for(int i = 1; i < n; i ++) {
        dp[i][0] = 1;
        for(int j = 0; j < i; j ++) {
            if(arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1) {
                dp[i][0] = dp[j][0] + 1;
            }
        }
    }

    for(int i = n-2; i >= 0; i --) {
        dp[i][1] = 1;
        for(int j = n-1; j >= i; j --) {
            if(arr[i] > arr[j] && dp[i][1] < dp[j][1] + 1) {
                dp[i][1] = dp[j][1] + 1;
            }
        }
    }

    for(int i = 0; i < n; i ++) {
        if(ans < dp[i][0] + dp[i][1] - 1) {
            ans = dp[i][0] + dp[i][1] - 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}