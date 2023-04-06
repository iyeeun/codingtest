#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> wines(n+1, 0);
  for(int i = 1; i <= n; i ++) cin >> wines[i];

  vector<vector<int> > dp(n+1, vector<int>(3, 0));

  dp[1][1] = wines[1];

  for(int i = 2; i <= n; i ++) {
    dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
    dp[i][1] = dp[i-1][0] + wines[i];
    dp[i][2] = dp[i-1][1] + wines[i];
  }

  cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
  
  return 0;
}