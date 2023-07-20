#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    vector<int> left;
    vector<int> right;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    for(int i = 0; i < (1 << n/2); i ++) {
        int sum = 0;
        for(int j = 0; j < n/2; j ++) {
            if(i & (1 << j)) {
                sum += arr[j];
            }
        }
        left.push_back(sum);
    }
    sort(left.begin(), left.end());

    int m = n - n/2;
    for(int i = 0; i < (1 << m); i ++) {
        int sum = 0;
        for(int j = 0; j < m; j ++) {
            if(i & (1 << j)) {
                sum += arr[n/2+j];
            }
        }
        right.push_back(sum);
    }
    sort(right.begin(), right.end(), [](int a, int b) {return a > b;});

    int idx1 = 0;
    int idx2 = 0;
    long ans = 0;
    while(idx1 < left.size() && idx2 < right.size()) {
        if(left[idx1] + right[idx2] == s) {
            long c1 = 1;
            long c2 = 1;
            idx1 ++;
            idx2 ++;
            while (idx1 < left.size() && left[idx1] == left[idx1-1]) {
                c1 ++;
                idx1 ++;
            }
            while (idx2 < right.size() && right[idx2] == right[idx2-1]) {
                c2 ++;
                idx2 ++;
            }
            ans += c1*c2;
        } else if(left[idx1] + right[idx2] < s) {
            idx1 ++;
        } else {
            idx2 ++;
        }
    }

    if (s == 0) ans -= 1;
    cout << ans << '\n';

    return 0;
}