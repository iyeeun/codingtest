#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long t;
    cin >> t;
    int n, m;
    cin >> n;
    vector<int> arr1(n);
    for(int i = 0; i < n; i ++) cin >> arr1[i];
    cin >> m;
    vector<int> arr2(m);
    for(int i = 0; i < m; i ++) cin >> arr2[i];

    vector<long> first;
    vector<long> second;

    for(int i = 0; i < n; i ++) {
        long s = 0;
        for(int j = i; j >= 0; j --) {
            s += arr1[j];
            first.push_back(s);
        }
    }
    for(int i = 0; i < m; i ++) {
        long s = 0;
        for(int j = i; j >= 0; j --) {
            s += arr2[j];
            second.push_back(s);
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    long ans = 0;
    for(int i = 0; i < first.size(); i ++) {
        auto res = equal_range(second.begin(), second.end(), t-first[i]);
        ans += (res.second - res.first);
    }
    cout << ans << "\n";

    return 0;
}