#include <iostream>
#include <string>
#include <cmath>

using namespace std;

 int main() {

    int n, m;
    cin >> n >> m;

    if(n == 100) {
        cout << "0\n";
        return 0;
    }
    if(m == 0) {
        int a = abs(100 - n);
        int b = to_string(n).length();
        cout << ((a > b)? b : a) << "\n";
        return 0;
    }

    int broken[10] = {0, };
    for(int i = 0; i < m; i ++) {
        int num;
        cin >> num;
        broken[num] = 1;
    }

    int res = abs(100 - n);

    for(int i = 0; i <= 1000000; i ++) {
        bool ispossible = true;
        int tmp = i;
        if(i == 0) {
            if(broken[0] == 1) {
                ispossible = false;
            }
        } else {
            while(tmp > 0) {
                if(broken[tmp%10] == 1) {
                    ispossible = false;
                    break;
                }
                tmp /= 10;
            }
        }

        if(ispossible) {
            int tmpres = abs(n - i) + to_string(i).length();
            if(res > tmpres) {
                res = tmpres;
            }
        }
    }

    cout << res << endl;

    return 0;
 }