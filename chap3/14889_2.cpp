#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int arr[20][20] = {0};
    int team = 0;
    int res = 10000000;
    vector<int> team1;
    vector<int> team2;

    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> arr[i][j];
        }
    }

    // All cases
    for(int i = 0; i < (1 << n); i ++) {
        int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;

        for(int j = 0; j < n; j ++) {
            if(i & (1 << j)) {
                cnt1 ++;
                team1.push_back(j);
            } else {
                cnt2 ++;
                team2.push_back(j);
            }
        }

        if(cnt1 != n/2 || cnt2 != n/2) {
            team1.clear();
            team2.clear();
            continue;
        } else {
            for(int j = 0; j < n/2; j ++) {
                for(int t = 0; t < n/2; t ++) {
                    sum1 += arr[team1[j]][team1[t]];
                    sum2 += arr[team2[j]][team2[t]];
                }
            }
            int tmp = (sum1 > sum2)? sum1 - sum2 : sum2 - sum1;
            if(tmp < res) res = tmp;
        }

    }

    cout << res << "\n";

    return 0;
}