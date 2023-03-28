#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long> arr(n+1, 0);

    if(n >= 2) arr[2] = 1;
    if(n >= 3) arr[3] = 1;

    for(int i = 4; i <= n; i ++) {
        arr[i] = arr[i-1] + 1;
        if(i % 2 == 0) arr[i] = min(arr[i], arr[i/2] + 1);
        if(i % 3 == 0) arr[i] = min(arr[i], arr[i/3] + 1);
    }

    cout << arr[n] << endl;

    return 0;
}