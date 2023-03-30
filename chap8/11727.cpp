#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> arr(n+1, 0);
  arr[1] = 1;
  if(n >= 2) arr[2] = 3;

  for(int i = 3; i <= n; i ++) {
    arr[i] = (arr[i-1] + (2*arr[i-2]) % 10007) % 10007;
  }

  cout << arr[n] << endl;

  return 0;
}