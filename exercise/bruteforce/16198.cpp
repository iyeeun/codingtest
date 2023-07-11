#include <iostream>
#include <vector>

using namespace std;

int ans = -1;

void getEnergy(vector<int> &weights, int sum) {
    if(weights.size() == 2) {
        if(ans == -1 || ans < sum) ans = sum;
        return;
    }

    for(int i = 1; i < weights.size()-1; i ++) {
        int x = weights[i];
        int add = weights[i-1] * weights[i+1];
        weights.erase(weights.begin()+i);
        getEnergy(weights, sum+add);
        weights.insert(weights.begin()+i, x);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for(int i = 0; i < n; i ++) cin >> weights[i];

    getEnergy(weights, 0);

    cout << ans << "\n";

    return 0;
}