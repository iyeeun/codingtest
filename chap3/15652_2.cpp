#include <iostream>

using namespace std;

int cnt[10] = {0};

void make_array(int idx, int n, int m, int selected) {
    if(selected == m) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j < cnt[i]; j ++) {
                cout << i << " ";
            }
        }
        cout << "\n";
        return;
    }

    if(idx > n) return;

    for(int i = m-selected; i >= 1; i --) {
        cnt[idx] = i;
        make_array(idx+1, n, m, selected+i);
    }
    cnt[idx] = 0;
    make_array(idx+1, n, m, selected);
}

int main() {
    int n, m;
    cin >> n >> m;

    make_array(1, n, m, 0);

    return 0;
}