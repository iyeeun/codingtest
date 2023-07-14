#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> arr[i][j];
        }
    }

    vector<int> players;
    for(int i = 0; i < n/2; i ++) {
        players.push_back(0);
    }
    for(int i = 0; i < n/2; i ++) {
        players.push_back(1);
    }

    int minval = 10000;
    while(true) {
        vector<int> t1;
        vector<int> t2;
        for(int i = 0; i < n; i ++) {
            if(players[i] == 0) {
                t1.push_back(i);
            } else {
                t2.push_back(i);
            }
        }
        int team1 = 0;
        int team2 = 0;
        for(int i = 0; i < n/2; i ++) {
            for(int j = 0; j < n/2; j ++) {
                team1 += arr[t1[i]][t1[j]];
                team2 += arr[t2[i]][t2[j]];
            }
        }
        int diff = (team1 - team2 >= 0)? team1 - team2 : team2 - team1;
        if(diff < minval) minval = diff;
        if(!next_permutation(players.begin(), players.end())) break;
    }

    cout << minval << '\n';

    return 0;
}