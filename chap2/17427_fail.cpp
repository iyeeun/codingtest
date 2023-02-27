// TIMEOUT

#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> f(n+1, 0);
  int res = 0;
  
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j*j <= i; j ++) {
      if(i%j == 0) {
        f[i] += j;
        if(j*j != i) {
          f[i] += (i/j);
        }
      }
    }
    res += f[i];
  }

  cout << res << endl;
  
  return 0;
}
