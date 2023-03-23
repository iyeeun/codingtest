#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    while(true) {
        cin >> k;
        if(k == 0) break;
        vector<int> arr(k);
        vector<int> select(k, 0);
        for(int i = 0; i < k; i ++) cin >> arr[i];
        for(int i = 0; i < 6; i ++) select[i] = 1;

        while(true) {
            for(int i = 0; i < k; i ++) {
                if(select[i]) cout << arr[i] << " ";
            }
            cout << "\n";

            if(!prev_permutation(select.begin(), select.end())) break;
        }
        cout << "\n";

    }

    return 0;
}