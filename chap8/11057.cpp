#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<vector<int> > dp(n+1, vector<int>(10, 0));
  
  for(int i = 0; i < 10; i ++) dp[1][i] = 1;
  
  for(int i = 2; i <= n; i ++) {
    for(int j = 0; j < 10; j ++) {
      for(int t = 0; t <= j; t ++) {
        dp[i][j] += dp[i-1][t];
        dp[i][j] %= 10007;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < 10; i ++) {
    ans += dp[n][i];
    ans %= 10007;
  }

  cout << ans << "\n";
  
  return 0;
}