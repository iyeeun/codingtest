#include <iostream>
#include <vector>
#include <string>

using namespace std;

int s[10][10] = {0};
int arr[10] = {0};
bool found = false;

void make_arr(int idx, int n) {
    if(found) return;

    if(idx == n) {
        for(int i = 0; i < n; i ++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        found = true;
        return;
    }

    if(s[idx][idx] == 0) {
        arr[idx] = 0;
        make_arr(idx+1, n);
    } else {
        int sign = s[idx][idx];
        for(int i = 1; i <= 10; i ++) {
            if(idx == 0) {
                arr[idx] = i*sign;
                make_arr(idx+1, n);
            } else {
                bool possible = true;
                int sum = 0;
                int sumidx = idx-1;
    
                while(sumidx >= 0) {
                    int sumsign = s[sumidx][idx];
                    sum += arr[sumidx];

                    if(sumsign == 0) {
                        int tmp = -sum;
                        if(sign == 0 && tmp == 0) {
                            arr[idx] = 0;
                            make_arr(idx+1, n);
                            possible = false;
                            break;
                        } else if(tmp * sign > 0) {
                            arr[idx] = tmp;
                            make_arr(idx+1, n);
                            possible = false;
                            break;
                        } else {
                            possible = false;
                        }
                    } else {
                        if((sum + sign*i) * sumsign <= 0) {
                            possible = false;
                        }
                    }
                    sumidx --;
                }

                if(possible) {
                    arr[idx] = i*sign;
                    make_arr(idx+1, n);
                }
            }
        }
    }

}

int main() {
    int n;
    string tmp;
    cin >> n;
    cin >> tmp;

    int idx = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = i; j < n; j ++) {
            if(tmp[idx] == '0') {
                s[i][j] = 0;
            } else if(tmp[idx] == '+') {
                s[i][j] = 1;
            } else if(tmp[idx] == '-') {
                s[i][j] = -1;
            }
            idx ++;
        }
    }

    make_arr(0, n);

    return 0;
}