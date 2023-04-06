#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<vector<int>> arr(n, vector<int>(n, -1));
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j <= i; j ++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(n, -1));
  dp[0][0] = arr[0][0];

  for(int i = 1; i < n; i ++) {
    dp[i][0] = dp[i-1][0] + arr[i][0];
    for(int j = 1; j <= i - 1; j ++) {
      dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
    }
    dp[i][i] = dp[i-1][i-1] + arr[i][i];
  }

  cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << "\n";
  
  return 0;
}