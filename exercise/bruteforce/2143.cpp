#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long t;
    int n, m;
    cin >> t >> n;
    vector<int> arr1(n);
    for(int i = 0; i < n; i ++) cin >> arr1[i];
    cin >> m;
    vector<int> arr2(m);
    for(int i = 0; i < m; i ++) cin >> arr2[i];

    vector<long> first;
    vector<long> second;

    for(int i = 0; i < n; i ++) {
        int tmp = 0;
        for(int j = i; j >= 0; j --) {
            tmp += arr1[j];
            first.push_back(tmp);
        }
    }
    for(int i = 0; i < m; i ++) {
        int tmp = 0;
        for(int j = i; j >= 0; j --) {
            tmp += arr2[j];
            second.push_back(tmp);
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), [](int a, int b) { return a > b; } );

    int idx1 = 0, idx2 = 0;
    long ans = 0;

    while(idx1 < first.size() && idx2 < second.size()) {
        if(first[idx1] + second[idx2] == t) {
            long c1 = 1;
            long c2 = 1;
            idx1 ++;
            idx2 ++;
            while(idx1 < first.size() && first[idx1] == first[idx1-1]) {
                c1 ++;
                idx1 ++;
            }
            while(idx2 < second.size() && second[idx2] == second[idx2-1]) {
                c2 ++;
                idx2 ++;
            }
            ans += c1 * c2;
            // cout << first[idx1-1] << " " << second[idx2-1] << "\t" << c1*c2 << "\n";
        } else if(first[idx1] + second[idx2] > t) {
            idx2 ++;
        } else {
            idx1 ++;
        }
    }

    cout << ans << '\n';

    return 0;
}