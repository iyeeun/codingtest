#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;

    vector<vector<int> > arr(h+x, vector<int>(w+y, 0));
    vector<vector<int> > ans(h, vector<int>(w, 0));

    for(int i = 0; i < h+x; i ++) {
        for(int j = 0; j < w+y; j ++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < x; i ++) {
        for(int j = 0; j < w; j ++) {
            ans[i][j] = arr[i][j];
            ans[h-x+i][j] = arr[h+i][y+j];
        }
    }

    for(int i = x; i < h; i ++) {
        for(int j = 0; j < y; j ++) {
            ans[i][j] = arr[i][j];
        }
        for(int j = y; j < w; j ++) { // overlap
            ans[i][j] = arr[i][j] - ans[i-x][j-y];
        }
    }

    for(int i = 0; i < h; i ++) {
        for(int j = 0; j < w; j ++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}