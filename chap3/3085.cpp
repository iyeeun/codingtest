#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findmax(int n, vector<string> &candy) {
    int max = 1;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            char c = candy[i][j];
            int tmpmax = 1;
            for(int t = j+1; t < n; t ++) {
                if(candy[i][t] != c) {
                    break;
                } else {
                    tmpmax ++;
                }
            }
            if(tmpmax > max) max = tmpmax;
            tmpmax = 1;
            for(int t = i+1; t < n; t ++) {
                if(candy[t][j] != c) {
                    break;
                } else {
                    tmpmax ++;
                }
            }
            if(tmpmax > max) max = tmpmax;
        }
    }

    return max;
}

int main() {
    int n;
    cin >> n;
    int max = 1;

    vector<string> candy(n);
    for(int i = 0; i < n; i ++) {
        cin >> candy[i];
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int res = 0;
            if(j != n-1) {
                swap(candy[i][j], candy[i][j+1]);
                res = findmax(n, candy);
                swap(candy[i][j], candy[i][j+1]);
            }
            if(res > max) max = res;
            if(i != n-1) {
                swap(candy[i][j], candy[i+1][j]);
                res = findmax(n, candy);
                swap(candy[i][j], candy[i+1][j]);
            }
            if(res > max) max = res;
        }
    }

    cout << max << endl;

    return 0;
}