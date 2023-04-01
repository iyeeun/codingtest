#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<vector<long>> arr(n+1, vector<long>(10)); 
  arr[1][0] = 0;
  for(int i = 1; i <= 9; i ++) arr[1][i] = 1;

  for(int i = 2; i <= n; i ++) {
    arr[i][0] = arr[i-1][1];
    for(int j = 1; j <= 8; j ++) {
      arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
    }
    arr[i][9] = arr[i-1][8];
  }

  long answer = 0;
  for(int i = 0; i <= 9; i ++) answer += (arr[n][i] % 1000000000);
  cout << answer % 1000000000 << "\n";

  
  return 0;
}