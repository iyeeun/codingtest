#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> dwarfs(9);
    int total = 0;
    int idx1 = 0, idx2 = 0;

    for(int i = 0; i < 9; i ++) {
        cin >> dwarfs[i];
        total += dwarfs[i];
    }

    for(int i = 0; i < 9; i ++) {
        for(int j = i+1; j < 9; j ++) {
            if(total - (dwarfs[i] + dwarfs[j]) == 100) {
                idx1 = i;
                idx2 = j;
                break;
            }
        }
    }

    dwarfs.erase(dwarfs.begin() + idx2);
    dwarfs.erase(dwarfs.begin() + idx1);
    sort(dwarfs.begin(), dwarfs.end());

    for(auto d : dwarfs) {
        cout << d << "\n";
    }

    return 0;
}