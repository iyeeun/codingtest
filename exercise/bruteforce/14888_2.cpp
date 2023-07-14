#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ops[4];
    for(int i = 0; i < n; i ++) cin >> nums[i];
    for(int i = 0; i < 4; i ++) cin >> ops[i];

    int maxval = -1000000000;
    int minval = 1000000000;

    vector<int> v;
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < ops[i]; j ++) {
            v.push_back(i);
        }
    }

    while(true) {
        int val = nums[0];
        for(int i = 0; i < n-1; i ++) {
            if(v[i] == 0) val += nums[i+1];
            else if(v[i] == 1) val -= nums[i+1];
            else if(v[i] == 2) val *= nums[i+1];
            else if(v[i] == 3) val /= nums[i+1];
        }
        if(val > maxval) maxval = val;
        if(val < minval) minval = val;
        if(!next_permutation(v.begin(), v.end())) break;
    }

    cout << maxval << '\n' << minval << '\n';


    return 0;
}