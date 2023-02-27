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

  vector<int> farr(max+1, 1);
  vector<long> garr(max+1, 1);

  for(int i = 2; i <= max; i ++) {
    for(int j = 1; i*j <= max; j ++) {
      farr[i*j] += i;
    }
    garr[i] = garr[i-1] + farr[i];
  }

  for(int i = 0; i < t; i ++) {
    cout << garr[cases[i]] << "\n";
  }
  
  return 0;
}
