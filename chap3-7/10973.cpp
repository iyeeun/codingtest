#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    if(prev_permutation(arr.begin(), arr.end())) {
        for(auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "-1\n";
    }

    return 0;
}