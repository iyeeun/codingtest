#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int arr[10] = {0};

    cin >> n;
    for(int i = 0; i < n; i ++) arr[i] = i+1;

    while(true) {
        for(int i = 0; i < n; i ++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        if(!next_permutation(arr, arr+n)) break;
    }

}