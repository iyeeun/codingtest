#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > board(9, vector<int>(9));
vector<pair<int, int> > blanks;
vector<vector<bool> > rows(9, vector<bool>(9, false));
vector<vector<bool> > cols(9, vector<bool>(9, false));
vector<vector<bool> > blocks(9, vector<bool>(9, false));

void solve(int idx) {
    if(blanks.size() == idx) {
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int row = blanks[idx].first;
    int col = blanks[idx].second;
    for(int i = 0; i < 9; i ++) {
        if(!rows[row][i] && !cols[col][i] && !blocks[(row/3)*3+(col/3)][i]) {
            board[row][col] = i+1;
            rows[row][i] = true;
            cols[col][i] = true;
            blocks[(row/3)*3+(col/3)][i] = true;
            solve(idx+1);
            board[row][col] = 0;
            rows[row][i] = false;
            cols[col][i] = false;
            blocks[(row/3)*3+(col/3)][i] = false;
        }
    }
}

int main() {

    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            cin >> board[i][j];
            if(board[i][j] != 0) {
                rows[i][board[i][j]-1] = true;
                cols[j][board[i][j]-1] = true;
                blocks[(i/3)*3+(j/3)][board[i][j]-1] = true;
            } else {
                blanks.push_back(make_pair(i, j));
            }
        }
    }

    solve(0);
    
    return 0;
}