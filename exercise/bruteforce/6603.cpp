#include <iostream>
#include <vector>

using namespace std;

vector<int> lotto;

void solve(vector<int> &arr, int idx, int cnt) {
    if(cnt == 6) {
        for(auto l : lotto) {
            cout << l << " ";
        }
        cout << "\n";
        return;
    }

    if(idx == arr.size()) return;

    lotto.push_back(arr[idx]);
    solve(arr, idx+1, cnt+1);
    lotto.pop_back();
    solve(arr, idx+1, cnt);
}

int main() {

    int k;

    while(true) {
        cin >> k;
        if(k == 0) break;

        vector<int> arr(k);
        for(int i = 0; i < k; i ++) cin >> arr[i];

        solve(arr, 0, 0);
        cout << "\n";
    }


    return 0;
}