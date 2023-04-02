#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;

  vector<vector<long> > dp(n+1, vector<long>(k+1));

  dp[0][0] = 1;

  for(int i = 0; i <= n; i ++) {
    for(int j = 1; j <= k; j ++) {
      for(int t = 0; t <= i; t ++) {
        dp[i][j] += (dp[i-t][j-1]) % 1000000000; 
        dp[i][j] %= 1000000000; 
      }
    }
  }

  cout << dp[n][k] << endl;
  
  return 0;
}