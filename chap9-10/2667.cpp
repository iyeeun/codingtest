#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int totalnum = 0;
int housenum = 0;

void dfs(int cur1, int cur2, vector<vector<int> > &arr, vector<vector<bool> > &visit) {
    if(arr[cur1][cur2] == 1) {
        visit[cur1][cur2] = true;
        housenum ++;
    }

    if(cur1 != 0 && arr[cur1-1][cur2] == 1 && !visit[cur1-1][cur2]) {
        dfs(cur1-1, cur2, arr, visit); 
    }
    if(cur1 != arr.size()-1 && arr[cur1+1][cur2] == 1 && !visit[cur1+1][cur2]) {
        dfs(cur1+1, cur2, arr, visit); 
    }
    if(cur2 != 0 && arr[cur1][cur2-1] == 1 && !visit[cur1][cur2-1]) {
        dfs(cur1, cur2-1, arr, visit); 
    }
    if(cur2 != arr.size()-1 && arr[cur1][cur2+1] == 1 && !visit[cur1][cur2+1]) {
        dfs(cur1, cur2+1, arr, visit); 
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> res;
    string inp;

    vector<vector<int> > arr(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        cin >> inp;
        for(int j = 0; j < n; j ++) {
            arr[i][j] = inp[j] - '0';
        }
    }

    vector<vector<bool> > visit(n, vector<bool>(n, false));

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(arr[i][j] == 0) continue;
            if(!visit[i][j]) {
                dfs(i, j, arr, visit);
                totalnum ++;
                res.push_back(housenum);
                housenum = 0;
            }
        }
    }

    cout << totalnum << "\n";
    sort(res.begin(), res.end());
    for(auto i : res) {
        cout << i << "\n";
    }

    return 0;
}