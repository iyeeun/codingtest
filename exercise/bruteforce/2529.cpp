#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<char> arr(k);
    char c;
    for(int i = 0; i < k; i ++) {
        cin >> arr[i]; 
    }

    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i <= k; i ++) {
        v1.push_back(i);
        v2.push_back(9-i);
    }

    while(true) {
        if(!next_permutation(v1.begin(), v1.end())) break;
        bool ok = true;
        for(int i = 0; i < k; i ++) {
            if(!((arr[i] == '<' && v1[i] < v1[i+1]) || (arr[i] == '>' && v1[i] > v1[i+1]))) {
                ok = false;
            }
        }
        if(ok) break;
    }

    while(true) {
        if(!prev_permutation(v2.begin(), v2.end())) break;
        bool ok = true;
        for(int i = 0; i < k; i ++) {
            if(!((arr[i] == '<' && v2[i] < v2[i+1]) || (arr[i] == '>' && v2[i] > v2[i+1]))) {
                ok = false;
            }
        }
        if(ok) break;
    }

    for(auto i : v2) {
        cout << i;
    }
    cout << "\n";
    for(auto i : v1) {
        cout << i;
    }
    cout << "\n";

    return 0;
}