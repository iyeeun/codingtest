// TIMEOUT

#include <iostream>
#include <vector>

using namespace std;

int main() {

  int t;
  cin >> t;
  int n;
  long res;
  int max = 0;
  vector<int> cases(t);

  for(int i = 0; i < t; i ++) {
    cin >> cases[i];
    if(cases[i] > max) max = cases[i];
  }

  vector<int> arr(max+1, 1);

  for(int i = 2; i <= max; i ++) {
    for(int j = 1; i*j <= max; j ++) {
      arr[i*j] += i;
    }
  }

  for(int i = 0; i < t; i ++) {
    long res = 0;
    for(int j = 1; j <= cases[i]; j ++) {
      res += arr[j];
    }
    cout << res << "\n";
  }
  
  return 0;
}
