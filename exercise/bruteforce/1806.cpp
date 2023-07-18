#include <iostream>
#include <vector>

using namespace std;

int main() {
    long n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];


    int ans = 0;
    int idx1 = 0;
    int idx2 = 0;
    long sum = arr[0];
    while(true) {
        if(sum >= s) {
            if(ans == 0 || ans > idx2-idx1+1) ans = idx2-idx1+1;
            if(idx1 == n-1) break;
            sum -= arr[idx1];
            idx1 ++;
            if(idx1 > idx2) {
                int tmp = idx1;
                idx1 = idx2;
                idx2 = tmp;
            }
        } else {
            if(idx2 == n-1) break;
            idx2 ++;
            sum += arr[idx2];
        }
    }

    cout << ans << '\n';

    return 0;
}