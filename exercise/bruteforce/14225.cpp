#include <iostream>
#include <vector>

using namespace std;

bool nums[2000001] = {false};

void solve(vector<int> &arr, int idx, int sum) {
    if(idx == arr.size()) {
        nums[sum] = true;
        return;
    }

    solve(arr, idx+1, sum);
    solve(arr, idx+1, sum+arr[idx]);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    solve(arr, 0, 0);

    for(int i = 1; i <= 2000000; i ++) {
        if(!nums[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}