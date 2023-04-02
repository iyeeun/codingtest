#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> arr(n+1);
  for(int i = 1; i <= n; i ++) cin >> arr[i];

  vector<int> dp(n+1);
  dp[1] = arr[1];

  for(int i = 2; i <= n; i ++) {
    dp[i] = max(arr[i], dp[i-1] + arr[i]);
  }

  cout << *max_element(dp.begin()+1, dp.end()) << endl;
  
  return 0;
}