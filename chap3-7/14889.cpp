#include <iostream>
#include <vector>

using namespace std;

int score[20][20];
int mindiff = 1000;

void find_diff(vector<int> &team1, vector<int> &team2, int idx, int n) {
    if(idx == n) {
        if(team1.size() == n/2 && team2.size() == n/2) {
            int sum1 = 0;
            int sum2 = 0;
            for(int i = 0; i < n/2; i ++) {
                for(int j = 0; j < n/2; j ++) {
                    sum1 += score[team1[i]][team1[j]];
                    sum2 += score[team2[i]][team2[j]];
                }
            }
            int diff = (sum1 > sum2)? (sum1 - sum2) : (sum2 - sum1);
            if(diff < mindiff) mindiff = diff;
        }
        return;
    }

    if(team1.size() > n/2 || team2.size() > n/2) return;

    team1.push_back(idx);
    find_diff(team1, team2, idx+1, n);
    team1.pop_back();

    team2.push_back(idx);
    find_diff(team1, team2, idx+1, n);
    team2.pop_back();
}

int main() {
    int n;
    vector<int> team1;
    vector<int> team2;

    cin >> n;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> score[i][j];
        }
    }

    find_diff(team1, team2, 0, n);

    cout << mindiff << "\n";

    return 0;
}