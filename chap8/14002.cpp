#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> arr(n+1);
  for(int i = 1; i <= n; i ++) cin >> arr[i];

  vector<int> dp(n+1);
  vector<int> lastidx(n+1);

  dp[1] = 1;
  lastidx[1] = 0;

  for(int i = 2; i <= n; i ++) {
    dp[i] = 1;
    lastidx[i] = 0;
    for(int j = 1; j < i; j ++) {
      if(arr[j] < arr[i] && dp[j]+1 > dp[i]) {
        dp[i] = dp[j]+1;
        lastidx[i] = j;
      }
    }
  }

  int idx = max_element(dp.begin(), dp.end()) - dp.begin();

  cout << *max_element(dp.begin(), dp.end()) << endl;

  stack<int> s;
  while(true) {
    if(idx == 0) break;
    s.push(arr[idx]);
    idx = lastidx[idx];
  }

  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  
  return 0;
}