#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  long res = 0;

  for(int i = 1; i <= n; i ++) {
    res += i*(n/i);
  }

  cout << res << endl;
  
  return 0;
}
