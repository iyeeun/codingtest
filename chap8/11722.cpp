#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> arr(n);
  vector<int> dp(n, 1);
  for(int i = 0; i < n; i ++) cin >> arr[i];

  for(int i = 1; i < n; i ++) {
    for(int j = 0; j < i; j ++) {
      if(arr[i] < arr[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
  
  return 0;
}