#include <iostream>
#include <vector>

using namespace std;

int main() {

  int t;
  cin >> t;
  vector<int> nums(t);
  int max = 0;
  int min = 1000000;

  for(int i = 0; i < t; i ++) {
    cin >> nums[i];
    if(nums[i] > max) max = nums[i];
    if(nums[i] < min) min = nums[i];
  }

  cout << min * max << endl;
  
  return 0;
}
