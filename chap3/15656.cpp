#include <iostream>
#include <algorithm>

using namespace std;

int nums[10] = {0};
int arr[10] = {0};
bool chosen[10] = {false};

void make_array(int idx, int n, int m) {
    if(idx == m) {
        for(int i = 0; i < m; i ++) {
            cout << nums[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i ++) {
        chosen[i] = true;
        arr[idx] = i;
        make_array(idx+1, n, m);
        chosen[i] = false;
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);

    make_array(0, n, m);

    return 0;
}