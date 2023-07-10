#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(2*n+1);
    vector<bool> robots(2*n+1, false);
    for(int i = 1; i <= 2*n; i ++) cin >> arr[i];

    long ans = 0;

    while(true) {
        ans ++;
        // rotate
        int tmp = arr[2*n];
        bool tmp2 = robots[2*n];
        for(int i = 2*n-1; i >= 1; i --) {
            arr[i+1] = arr[i];
            robots[i+1] = robots[i];
            if(i+1 >= n && robots[i+1]) {
                robots[i+1] = false;
            }
        }
        arr[1] = tmp;
        robots[1] = tmp2;

        // robot
        for(int i = n; i >= 1; i --) {
            if(!robots[i]) continue;
            if(arr[i+1] >= 1 && !robots[i+1]) {
                robots[i] = false;
                robots[i+1] = true;
                arr[i+1] --;
            }
        }

        // up
        if(arr[1] != 0) {
            robots[1] = true;
            arr[1] --;
        }

        // count
        if(count(arr.begin()+1, arr.end(), 0) >= k) {
            break;
        }
        
    }

    cout << ans << "\n";

    return 0;
}