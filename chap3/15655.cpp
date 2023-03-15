#include <iostream>
#include <algorithm>

using namespace std;

int nums[10] = {0};
int arr[10] = {0};

void make_array(int idx, int n, int m, int selected) {
    if(selected == m) {
        for(int i = 0; i < m; i ++) {
            cout << nums[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }

    if(idx >= n) return;
    arr[selected] = idx;
    make_array(idx+1, n, m, selected+1);
    arr[selected] = 0;
    make_array(idx+1, n, m, selected);
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);

    make_array(0, n, m, 0);

    return 0;
}