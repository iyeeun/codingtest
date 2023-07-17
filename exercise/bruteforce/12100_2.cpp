#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gen(int k) {
    vector<int> a(5);
    for (int i=0; i<5; i++) {
        a[i] = (k&3);
        k >>= 2;
    }
    return a;
}

int move(vector<vector<int> > arr, vector<int> &dirs, int n) {

    if(dirs.size() > 5) cout << "size\n";
    
    for(int dir : dirs) {
        vector<vector<bool> > com(n, vector<bool>(n, false));

        if(dir == 0) { // UP
            for(int i = 1; i < n; i ++) {
                for(int j = 0; j < n; j ++) {
                    if(arr[i][j] == 0) continue;
                    int dst = i;
                    while(true) {
                        if(dst == 0) break;
                        if(arr[dst-1][j] == 0) {
                            arr[dst-1][j] = arr[dst][j];
                            com[dst-1][j] = com[dst][j];
                            arr[dst][j] = 0;
                            dst --;
                        } else if(arr[dst-1][j] != arr[dst][j]) {
                            break;
                        } else if(arr[dst-1][j] == arr[dst][j]) {
                            if(!com[dst-1][j] && !com[dst][j]) {
                                arr[dst-1][j] *= 2;
                                com[dst-1][j] = true;
                                arr[dst][j] = 0;
                                dst --;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        } else if(dir == 1) { // DOWN
            for(int i = n-2; i >= 0; i --) {
                for(int j = 0; j < n; j ++) {
                    if(arr[i][j] == 0) continue;
                    int dst = i;
                    while(true) {
                        if(dst == n-1) break;
                        if(arr[dst+1][j] == 0) {
                            arr[dst+1][j] = arr[dst][j];
                            com[dst+1][j] = com[dst][j];
                            arr[dst][j] = 0;
                            dst ++;
                        } else if(arr[dst+1][j] != arr[dst][j]) {
                            break;
                        } else if(arr[dst+1][j] == arr[dst][j]) {
                            if(!com[dst+1][j] && !com[dst][j]) {
                                arr[dst+1][j] *= 2;
                                com[dst+1][j] = true;
                                arr[dst][j] = 0;
                                dst ++;    
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        } else if(dir == 2) { // LEFT
            for(int i = 0; i < n; i ++) {
                for(int j = 1; j < n; j ++) {
                    if(arr[i][j] == 0) continue;
                    int dst = j;
                    while(true) {
                        if(dst == 0) break;
                        if(arr[i][dst-1] == 0) {
                            arr[i][dst-1] = arr[i][dst];
                            com[i][dst-1] = com[i][dst];
                            arr[i][dst] = 0;
                            dst --;
                        } else if(arr[i][dst-1] != arr[i][dst]) {
                            break;
                        } else if(arr[i][dst-1] == arr[i][dst]) {
                            if(!com[i][dst-1] && !com[i][dst]) {
                                arr[i][dst-1] *= 2;
                                com[i][dst-1] = true;
                                arr[i][dst] = 0;
                                dst --;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        } else if(dir == 3) { // RIGHT
            for(int i = 0; i < n; i ++) {
                for(int j = n-2; j >= 0; j --) {
                    if(arr[i][j] == 0) continue;
                    int dst = j;
                    while(true) {
                        if(dst == n-1) break;
                        if(arr[i][dst+1] == 0) {
                            arr[i][dst+1] = arr[i][dst];
                            arr[i][dst] = 0;
                            dst ++;
                        } else if(arr[i][dst+1] != arr[i][dst]) {
                            break;
                        } else if(arr[i][dst+1] == arr[i][dst]) {
                            if(!com[i][dst+1] && !com[i][dst]) {
                                arr[i][dst+1] *= 2;
                                com[i][dst+1] = true;
                                arr[i][dst] = 0;
                                dst ++;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int m = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(m < arr[i][j]) m = arr[i][j];
        }
    }

    return m;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> arr[i][j];
        }
    }

    int maxval = 0;

    for(int i = 0; i < (1 << (5*2)); i ++) {
        vector<int> dirs = gen(i);
        int cur = move(arr, dirs, n);
        if(maxval < cur) {
            maxval = cur;
        }
    }

    cout << maxval << '\n';

    return 0;
}