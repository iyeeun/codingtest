#include <iostream>

using namespace std;

int arr[8];

void make_array(int idx, int n, int m) {
    if(idx == m) {
        for(int i = 0; i < m; i ++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i ++) {
        arr[idx] = i;
        make_array(idx+1, n, m);
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    make_array(0, n, m);

    return 0;
}