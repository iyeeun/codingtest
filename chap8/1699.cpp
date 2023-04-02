#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> dp(n+1);
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i ++) {
    dp[i] = i;
    for(int j = 1; j*j <= i; j ++) {
      if(dp[i-j*j] + 1 < dp[i]) {
        dp[i] = dp[i-j*j] + 1;
      }
    }
  }

  cout << dp[n] << endl;
  
  return 0;
}