#include <iostream>

using namespace std;

bool ispicked[9] = {false, };
int arr[9];

void make_array(int idx, int n, int m) {
    if(idx == m) {
        for(int i = 0; i < m; i ++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i ++) {
        if(ispicked[i]) continue;
        ispicked[i] = true;
        arr[idx] = i;
        make_array(idx+1, n, m);
        ispicked[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    make_array(0, n, m);

    return 0;
}