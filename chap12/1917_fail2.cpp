#include <iostream>

using namespace std;

int cond[7] = {0, };

void check(int i, int j, int (*arr)[6], int cur) {
    arr[i][j] = -1;
    // down
    if(i != 5 && arr[i+1][j] == 1) {
        int target;
        if(cur == 1) target = 3;
        else if(cur == 2) target = 4;
        else if(cur == 3) target = 2;
        else if(cur == 4) target = 1;
        else if(cur == 5 || cur == 6) target = 3;
        cond[target] = 1;
        check(i+1, j, arr, target);
    }
    // left
    if(j != 0 && arr[i][j-1] == 1) {
        int target;
        if(cur == 1 || cur == 2 || cur == 3 || cur == 4) target = 6;
        else if(cur == 5) target = 3;
        else if(cur == 6) target = 4;
        cond[target] = 1;
        check(i, j-1, arr, target);
    }
    // right
    if(j != 5 && arr[i][j+1] == 1) {
        int target;
        if(cur == 1 || cur == 2 || cur == 3 || cur == 4) target = 5;
        else if(cur == 5) target = 4;
        else if(cur == 6) target = 3;
        cond[target] = 1;
        check(i, j+1, arr, target);
    }
}

int main() {

    int inp[6][6];
    int fx, fy, first;

    for(int t = 0; t < 3; t ++) {
        for(int i = 0; i < 7; i ++) cond[i] = 0;
        first = 0;

        for(int i = 0; i < 6; i ++) {
            for(int j = 0; j < 6; j ++) {
                cin >> inp[i][j];
                if(inp[i][j] == 1 && first == 0) {
                    first = 1;
                    fx = i; fy = j;
                }
            }
        }

        cond[1] = 1;
        check(fx, fy, inp, 1);

        bool ok = true;
        for(int i = 1; i < 7; i ++) {
            if(cond[i] != 1) {
                ok = false;
                break;
            }
        }
        if(ok) cout << "yes\n";
        else cout << "no\n";

    }

    return 0;
}