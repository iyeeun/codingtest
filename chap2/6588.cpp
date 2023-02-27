#include <iostream>
#include <vector>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<bool> isprime(1000001, true);

  for(int i = 3; i <= 1000000; i += 2) {
    if(isprime[i]) {
      for(int j = 2*i; j <= 1000000; j += i) {
        isprime[j] = false;
      }
    }
  }
  
  while(true) {
    cin >> n;
    if(n == 0) break;

    int a, b;
    bool possible = false;
    for(int i = 3; i <= n; i += 2) {
      if(isprime[i] && isprime[n-i]) {
        a = i;
        b = n-i;
        possible = true;
        break;
      }
    }

    if(possible) {
      cout << n << " = " << a << " + " << b << "\n";
    } else {
      cout << "Goldbach's conjecture is wrong.\n";
    }
    
    
  }


  return 0;
}