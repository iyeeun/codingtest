#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    long ans = 0;
    int idx1 = 0;
    int idx2 = 0;
    long sum = arr[0];
    while(true) {
        if(idx1 == n) break;
        if(sum < m) {
            if(idx2 != n-1) {
                idx2 ++;
                sum += arr[idx2];
            } else {
                sum -= arr[idx1];
                idx1 ++;
            }
        } else if(sum == m) {
            ans ++;
            sum -= arr[idx1];
            idx1 ++;
            if(idx2 != n-1) {
                idx2 ++;
                sum += arr[idx2];
            }
        } else {
            if(idx1 == idx2) {
                idx1 ++;
                idx2 ++;
                sum = arr[idx1];
            } else {
                sum -= arr[idx1];
                idx1 ++;
            }  
        }
    }

    cout << ans << '\n';

    return 0;
}