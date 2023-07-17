#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxval = 0;

void move(vector<vector<int> > &arr, int cnt, int dir, int n) {
    if(cnt >= 5) {
        for(auto i : arr) {
            int t = *max_element(i.begin(), i.end());
            if(t > maxval) maxval = t;
        }
        
        return;
    }

    vector<vector<int> > tmp(arr);
    vector<vector<bool> > com(n, vector<bool>(n, false));

    if(dir == 0) { // UP
        for(int i = 1; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(tmp[i][j] == 0) continue;
                int dst = i;
                while(true) {
                    if(dst == 0) break;
                    if(tmp[dst-1][j] == 0) {
                        tmp[dst-1][j] = tmp[dst][j];
                        com[dst-1][j] = com[dst][j];
                        tmp[dst][j] = 0;
                        dst --;
                    } else if(tmp[dst-1][j] != tmp[dst][j]) {
                        break;
                    } else if(tmp[dst-1][j] == tmp[dst][j]) {
                        if(!com[dst-1][j] && !com[dst][j]) {
                            tmp[dst-1][j] *= 2;
                            com[dst-1][j] = true;
                            tmp[dst][j] = 0;
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
                if(tmp[i][j] == 0) continue;
                int dst = i;
                while(true) {
                    if(dst == n-1) break;
                    if(tmp[dst+1][j] == 0) {
                        tmp[dst+1][j] = tmp[dst][j];
                        com[dst+1][j] = com[dst][j];
                        tmp[dst][j] = 0;
                        dst ++;
                    } else if(tmp[dst+1][j] != tmp[dst][j]) {
                        break;
                    } else if(tmp[dst+1][j] == tmp[dst][j]) {
                        if(!com[dst+1][j] && !com[dst][j]) {
                            tmp[dst+1][j] *= 2;
                            com[dst+1][j] = true;
                            tmp[dst][j] = 0;
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
                if(tmp[i][j] == 0) continue;
                int dst = j;
                while(true) {
                    if(dst == 0) break;
                    if(tmp[i][dst-1] == 0) {
                        tmp[i][dst-1] = tmp[i][dst];
                        com[i][dst-1] = com[i][dst];
                        tmp[i][dst] = 0;
                        dst --;
                    } else if(tmp[i][dst-1] != tmp[i][dst]) {
                        break;
                    } else if(tmp[i][dst-1] == tmp[i][dst]) {
                        if(!com[i][dst-1] && !com[i][dst]) {
                            tmp[i][dst-1] *= 2;
                            com[i][dst-1] = true;
                            tmp[i][dst] = 0;
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
                if(tmp[i][j] == 0) continue;
                int dst = j;
                while(true) {
                    if(dst == n-1) break;
                    if(tmp[i][dst+1] == 0) {
                        tmp[i][dst+1] = tmp[i][dst];
                        tmp[i][dst] = 0;
                        dst ++;
                    } else if(tmp[i][dst+1] != tmp[i][dst]) {
                        break;
                    } else if(tmp[i][dst+1] == tmp[i][dst]) {
                        if(!com[i][dst+1] && !com[i][dst]) {
                            tmp[i][dst+1] *= 2;
                            com[i][dst+1] = true;
                            tmp[i][dst] = 0;
                            dst ++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < 4; i ++) move(tmp, cnt+1, i, n);
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

    for(int i = 0; i < 4; i ++) move(arr, 0, i, n);
    cout << maxval << '\n';

    return 0;
}