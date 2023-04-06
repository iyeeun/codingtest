#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long> nums(n);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    vector<long> start_dp(n);
    vector<long> end_dp(n);

    start_dp[0] = nums[0];
    for(int i = 1; i < n; i ++) {
        start_dp[i] = max(start_dp[i-1] + nums[i], nums[i]);
    }

    end_dp[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i --) {
        end_dp[i] = max(end_dp[i+1] + nums[i], nums[i]);
    }

    long ans = start_dp[0];
    for(int i = 1; i < n; i ++) {
        if(start_dp[i] > ans) ans = start_dp[i];
    }
    for(int i = 1; i <= n-2; i ++) {
        if(start_dp[i-1] + end_dp[i+1] > ans) ans = start_dp[i-1] + end_dp[i+1];
    }

    cout << ans << endl;

    return 0;
}