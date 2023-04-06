#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, t;
  cin >> t;

  long arr[1000001] = {0};
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;

  long max = 3;

  for(int i = 0; i < t; i ++) {
    cin >> n;
    if(n > max) {
      for(int j = max+1; j <= n; j ++) {
        arr[j] = (arr[j-1] + arr[j-2] + arr[j-3]) % 1000000009;
      }
    }
    cout << arr[n] << "\n";
  }
  
  return 0;
}