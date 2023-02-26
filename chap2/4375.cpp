#include <iostream>

using namespace std;

int main() {

  int n;

  while(cin >> n) {
    int num = 1;
    int res = 1 % n;
    while(res != 0) {
      res = (res*10 + 1) % n;
      num ++;
    }
    cout << num << "\n";
  }
  
  return 0;
}
