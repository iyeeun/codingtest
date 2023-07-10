#include <iostream>
#include <vector>

using namespace std;

long maxval = -1000000000;
long minval = 1000000000;

void solve(vector<int> &arr, vector<int> &ops, int idx, long sum) {
    if(idx == arr.size()) {
        if(sum > maxval) maxval = sum;
        if(sum < minval) minval = sum;
        return;
    }

    for(int i = 0; i < 4; i ++) {
        if(ops[i] > 0) {
            ops[i] --;
            if(i == 0) solve(arr, ops, idx+1, sum+arr[idx]);
            else if(i == 1) solve(arr, ops, idx+1, sum-arr[idx]);
            else if(i == 2) solve(arr, ops, idx+1, sum*arr[idx]);
            else if(i == 3) solve(arr, ops, idx+1, sum/arr[idx]);
            ops[i] ++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    vector<int> ops(4);
    for(int i = 0; i < 4; i ++) cin >> ops[i];

    solve(arr, ops, 1, arr[0]);

    cout << maxval << "\n" << minval << "\n";

    return 0;
}