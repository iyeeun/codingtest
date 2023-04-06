#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> arr(n);
  vector<int> dp(n);
  for(int i = 0; i < n; i ++) cin >> arr[i];

  dp[0] = arr[0];
  for(int i = 1; i < n; i ++) {
    dp[i] = arr[i];
    for(int j = 0; j < i; j ++) {
      if(arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) {
        dp[i] = dp[j] + arr[i];
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << "\n";
  
  return 0;
}