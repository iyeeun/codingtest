#include <iostream>

using namespace std;

bool ispicked[9] = {false, };
int arr[8] = {0};

void make_arr(int idx, int n, int m, int prev) {

    if(idx == m) {
        for(int i = 0; i < m; i ++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i ++) {
        if(ispicked[i]) continue;
        if(i < prev) continue;
        ispicked[i] = true;
        arr[idx] = i;
        make_arr(idx+1, n, m, i);
        ispicked[i] = false;
    }

}

int main() {

    int n, m;
    cin >> n >> m;

    make_arr(0, n, m, 0);

    return 0;
}