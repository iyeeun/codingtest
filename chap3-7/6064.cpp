#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i ++) {
        int m, n, x, y;
        bool possible = false;
        cin >> m >> n >> x >> y;

        if(y == n) y = 0;

        for(int j = 0; j < n; j ++) {
            int num1 = j*m + x;
            int num2 = num1 % n;
            if(num2 == y) {
                possible = true;
                cout << num1 << "\n";
                break;
            }
        }

        if(!possible) {
            cout << "-1\n";
        }

    }

    return 0;
}