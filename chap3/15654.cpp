#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int selected[10] = {0};
bool chosen[10] = {false};

void make_array(vector<int> &arr, int n, int m, int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i ++) {
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i ++) {
        if(chosen[i]) continue;
        chosen[i] = true;
        selected[idx] = arr[i];
        make_array(arr, n, m, idx+1);
        chosen[i] = false;
    }

}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    make_array(arr, n, m, 0);

    return 0;
}