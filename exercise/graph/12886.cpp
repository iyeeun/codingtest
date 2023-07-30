#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ans = false;

void dfs(vector<vector<bool> > &visit, int a, int b, int sum) {
    int c = sum - a - b;

    if(visit[a][b]) {
        return;
    }

    if(a == b && a == sum/3) {
        ans = true;
        return;
    }

    visit[a][b] = true;
    b -= a;
    a *= 2;
    dfs(visit, min(a, b), max(a, b), sum);
    dfs(visit, min(a, c), max(a, c), sum);
    dfs(visit, min(b, c), max(b, c), sum);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;

    if(sum % 3 != 0) {
        cout << "0\n";
        return 0;
    }
    vector<vector<bool> > visit(sum+1, vector<bool>(sum+1, false));

    int minval = min(min(a, b), c);
    int maxval = max(max(a, b), c);

    dfs(visit, minval, maxval, sum);

    if(ans) cout << "1\n";
    else cout << "0\n";

    return 0;
}