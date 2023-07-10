#include <iostream>

using namespace std;

int main() {
    int inp[6][6];

    for(int t = 0; t < 3; t ++) {
        int minx = 6, maxx = -1, miny = 6, maxy = -1;
        for(int i = 0; i < 6; i ++) {
            for(int j = 0; j < 6; j ++) {
                cin >> inp[i][j];
                if(inp[i][j] == 1) {
                    if(minx > j) minx = j;
                    if(maxx < j) maxx = j;
                    if(miny > i) miny = i;
                    if(maxy < i) maxy = i;
                }
            }
        }
        if((maxx-minx == 2 && maxy-miny == 3) || (maxx-minx == 3 && maxy-miny == 2)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}