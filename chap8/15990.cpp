#include <iostream>

using namespace std;

int main() {

  int t, n;
  cin >> t;

  long dp[100001] = {0};
  long arr1[100001] = {0};
  long arr2[100001] = {0};
  long arr3[100001] = {0};

  arr1[1] = 1;
  arr2[2] = 1;
  arr1[3] = arr2[3] = arr3[3] = 1;

  for(int i = 1; i <= 3; i ++) {
    dp[i] = arr1[i] + arr2[i] + arr3[i];
  }

  int max = 3;

  for(int i = 0; i < t; i ++) {
    cin >> n;

    if(n > max) {
      for(int j = max+1; j <= n; j ++) {
        arr1[j] = (arr2[j-1] + arr3[j-1]) % 1000000009;
        arr2[j] = (arr1[j-2] + arr3[j-2]) % 1000000009;
        arr3[j] = (arr1[j-3] + arr2[j-3]) % 1000000009;
        dp[j] = (arr1[j] + arr2[j] + arr3[j]) % 1000000009;
      }
      max = n;
    }

    cout << dp[n] << "\n";
    
  }
  
  return 0;
}