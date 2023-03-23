#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > w(n, vector<int>(n, 0));
    vector<int> arr(n);
    int min = 10000000;

    for(int i = 0; i < n; i ++) arr[i] = i;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> w[i][j];
        }
    }

    while(true) {
        int tmpsum = 0;
        bool possible = true;
        for(int i = 0; i < n; i ++) {
            int first = i;
            int second = i+1;
            if(first == n-1) second = 0;

            if(w[arr[first]][arr[second]] == 0) {
                possible = false;
                break;
            }
            tmpsum += w[arr[first]][arr[second]];
        }

        if(possible) {
            if(tmpsum < min) {
                min = tmpsum;
            }
        }
        if(!next_permutation(arr.begin()+1, arr.end())) break;
    }

    cout << min << "\n";

    return 0;
}