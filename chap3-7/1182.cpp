#include <iostream>

using namespace std;

int main() {
    int n, s;
    int arr[20] = {0};
    cin >> n >> s;
    
    int res = 0;
    
    for(int i = 0; i < n; i ++) cin >> arr[i];
    
    for(int i = 1; i < (1 << n); i ++) {
        int sum = 0;
        for(int j = 0; j < n; j ++) {
            if(i & (1 << j)) {
                sum += arr[j];
            }
        }
        if(sum == s) res ++;
    }

    cout << res << endl;

    return 0;
}