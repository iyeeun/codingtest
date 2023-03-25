#include <iostream>

using namespace std;

int find_num(int sum, int n) {
    if(sum > n) return 0;
    if(sum == n) return 1;

    int res = 0;
    for(int i = 1; i <= 3; i ++) {
        res += find_num(sum+i, n);
    }
    return res;
}

int main() {

    int t, n;
    cin >> t;

    for(int i = 0; i < t; i ++) {
        cin >> n;
        cout << find_num(0, n) << "\n";
    }

    return 0;
}