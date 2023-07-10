#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void solve(vector<int> &arr, int s, int idx, int sum) {
    if(idx == arr.size()) {
        if(s == sum) ans ++;
        return;
    }

    solve(arr, s, idx+1, sum+arr[idx]);
    solve(arr, s, idx+1, sum);
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for(int i = 0 ; i < n; i ++) cin >> arr[i];

    solve(arr, s, 0, 0);

    if(s == 0) ans --;
    cout << ans << "\n";

    return 0;
}