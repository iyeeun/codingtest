#include <iostream>

using namespace std;

int cond[6] = {0, };
int cube[6] = {0, 1, 2, 3, 4, 5};

void goLeft() {
    int tmp1 = cube[0];
    int tmp2 = cube[1];
    cube[0] = cube[5];
    cube[1] = cube[4];
    cube[4] = tmp1;
    cube[5] = tmp2;
}

void goRight() {
    int tmp1 = cube[0];
    int tmp2 = cube[1];
    cube[0] = cube[4];
    cube[1] = cube[5];
    cube[4] = tmp2;
    cube[5] = tmp1;
}

void goBack() {
    int tmp1 = cube[0];
    int tmp2 = cube[1];
    cube[0] = cube[3];
    cube[1] = cube[2];
    cube[2] = tmp1;
    cube[3] = tmp2;
}

void goFront() {
    int tmp1 = cube[0];
    int tmp2 = cube[1];
    cube[0] = cube[2];
    cube[1] = cube[3];
    cube[2] = tmp2;
    cube[3] = tmp1;
}

void check(int i, int j, int (*arr)[6]) {
    cond[cube[0]] = 1;
    arr[i][j] = -1;
    if(j > 0 && arr[i][j-1] == 1) {
        goLeft();
        check(i, j-1, arr);
        goRight();
    }
    if(j < 5 && arr[i][j+1] == 1) {
        goRight();
        check(i, j+1, arr);
        goLeft();
    }
    if(i > 0 && arr[i-1][j] == 1) {
        goBack();
        check(i-1, j, arr);
        goFront();
    }
    if(i < 5 && arr[i+1][j] == 1) {
        goFront();
        check(i+1, j, arr);
        goBack();
    }
}

int main() {

    int inp[6][6];
    int fx, fy, first;

    for(int t = 0; t < 3; t ++) {
        for(int i = 0; i < 6; i ++) {
            cond[i] = 0;
            cube[i] = i;
        }
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

        check(fx, fy, inp);

        bool ok = true;
        for(int i = 0; i < 6; i ++) {
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