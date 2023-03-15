#include <iostream>

using namespace std;

int n;
int period[15] = {0};
int price[15] = {0};
int res = 0;

void find_max(int day, int sum) {
    if(day == n) {
        if(sum > res) res = sum;
        return;
    }
    
    if(day > n) return;

    find_max(day+1, sum);
    find_max(day+period[day], sum+price[day]);
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i ++) {
        cin >> period[i] >> price[i];
    }

    find_max(0, 0);
    cout << res << endl;

    return 0;
}