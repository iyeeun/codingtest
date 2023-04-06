#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<vector<int>> costs(n+1, vector<int>(3, 0)); 
  for(int i = 1; i <= n; i ++) {
    cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
  }

  vector<vector<int>> dp(n+1, vector<int>(3, 0));
  for(int i = 0; i < 3; i ++) dp[1][i] = costs[1][i];
  for(int i = 2; i <= n; i ++) {
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
  }

  cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
  
  return 0;
}