#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> prime(4000001, true);
    for(int i = 2; i <= 4000000; i ++) {
        if(!prime[i]) continue;
        for(int j = 2*i; j <= 4000000; j += i) {
            prime[j] = false;
        }
    }

    vector<int> p;
    for(int i = 2; i <= 4000000; i ++) {
        if(prime[i]) p.push_back(i);
    }

    long n;
    cin >> n;

    int idx1 = 0;
    int idx2 = 0;
    long ans = 0;
    long sum = 2;
    while(idx1 <= idx2 && p[idx1] <= n && idx2 < p.size()) {
        if(sum < n) {
            idx2 ++;
            sum += p[idx2];
        } else {
            if(sum == n) {
                ans ++;
            }
            sum -= p[idx1];
            idx1 ++;
            if(idx1 > idx2) {
                int t = idx1;
                idx1 = idx2;
                idx2 = t;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}