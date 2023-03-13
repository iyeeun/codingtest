#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> m >> n;

    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;

    for(int i = 2; i * i <= n; i ++) {
        if(isprime[i]) {
            for(int j = 2*i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }

    for(int i = m; i <= n; i ++) {
        if(isprime[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}