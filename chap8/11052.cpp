#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> price(n+1);
  vector<int> dp(n+1);
  for(int i = 1; i <= n; i ++) cin >> price[i];

  dp[1] = price[1];
  for(int i = 2; i <= n; i ++) {
    dp[i] = price[i];
    for(int j = 1; j < i; j ++) {
      if(dp[i] < dp[i-j] + price[j]) {
        dp[i] = dp[i-j] + price[j];
      }
    }
  }

  cout << dp[n] << endl;
  
  return 0;
}