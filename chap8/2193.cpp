#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  long arr[91][2] = {0};
  arr[1][1] = 1;
  arr[2][0] = 1;

  for(int i = 3; i <= n; i ++) {
    arr[i][0] = arr[i-1][1] + arr[i-1][0];
    arr[i][1] = arr[i-1][0];
  }

  cout << arr[n][0] + arr[n][1] << endl;
  
  return 0;
}