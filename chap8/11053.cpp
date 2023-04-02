#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i ++) cin >> arr[i];

  vector<int> dp(n);
  dp[0] = 1;

  for(int i = 1; i < n; i ++) {
    dp[i] = 1;
    for(int j = 0; j < i; j ++) {
      if(arr[j] < arr[i] && dp[j]+1 > dp[i]) {
        dp[i] = dp[j]+1;
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
  
  return 0;
}