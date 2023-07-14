#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    bool check[2000001] = {false, };

    for(int i = 0; i < (1 << n); i ++) {
        int sum = 0;
        for(int j = 0; j < n; j ++) {
            if(i & (1 << j)) {
                sum += arr[j];
            }
        }
        check[sum] = true;
    }

    for(int i = 1; i <= 2000000; i ++) {
        if(!check[i]) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}