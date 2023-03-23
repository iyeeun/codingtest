#include <iostream>
#include <vector>

using namespace std;

int n;
int score[20][20];
int mindiff = 10000;

void find_mindiff(int idx, vector<int> &team1, vector<int> &team2) {
    if(idx == n) {
        if(team1.size() == 0 || team2.size() == 0) return;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < team1.size(); i ++) {
            for(int j = 0; j < team1.size(); j ++) {
                sum1 += score[team1[i]][team1[j]];
            }
        }
        for(int i = 0; i < team2.size(); i ++) {
            for(int j = 0; j < team2.size(); j ++) {
                sum2 += score[team2[i]][team2[j]];
            }
        }
        int diff = (sum1 > sum2)? (sum1 - sum2) : (sum2 - sum1);
        if(diff < mindiff) mindiff = diff;
        return;
    }

    team1.push_back(idx);
    find_mindiff(idx+1, team1, team2);
    team1.pop_back();

    team2.push_back(idx);
    find_mindiff(idx+1, team1, team2);
    team2.pop_back();

}

int main() {
    cin >> n;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> score[i][j];
        }
    }

    vector<int> team1;
    vector<int> team2;

    find_mindiff(0, team1, team2);

    cout << mindiff << "\n";

    return 0;
}