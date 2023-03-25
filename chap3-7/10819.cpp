#include <iostream>
#include <algorithm>

using namespace std;

int get_max(int n, int arr[]) {
    int sum = 0;
    for(int i = 0; i < n-1; i ++) {
        sum += ((arr[i] > arr[i+1])? arr[i]-arr[i+1] : arr[i+1]-arr[i]);
    }
    return sum;
}

int main() {
    int n;
    int arr[10] = {0};
    cin >> n;

    for(int i = 0; i < n; i ++) cin >> arr[i];

    sort(arr, arr+n);

    int max = 0;
    while(true) {
        int tmp = get_max(n, arr);
        if(tmp > max) max = tmp;
        if(!next_permutation(arr, arr+n)) break;
    }

    cout << max << endl;

    return 0;
}