#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, int> > dominos;
vector<vector<bool> > rows;
vector<vector<bool> > cols;
vector<vector<bool> > blocks;

int dx[] = {0, 1};
int dy[] = {1, 0};
int cnt = 0;

bool solve(vector<vector<int> > &board, int idx) {
    if(idx == 81) {
        cout << "Puzzle " << cnt << "\n";
        for(auto i : board) {
            for(auto j : i) {
                cout << j;
            }
            cout << "\n";
        }
        return true;
    }

    int x = idx / 9;
    int y = idx % 9;

    if(board[x][y] != 0) {
        return solve(board, idx+1);
    } else {
        for(int i = 0; i < 2; i ++) {
            int px = x + dx[i];
            int py = y + dy[i];
            if(px >= 9 || py >= 9) continue;
            if(board[px][py] != 0) continue;
            for(int t1 = 0; t1 < 9; t1 ++) {
                for(int t2 = 0; t2 < 9; t2 ++) {
                    if(t1 == t2) continue;
                    if(!rows[x][t1] && !cols[y][t1] && !blocks[(x/3)*3+(y/3)][t1] && 
                    !rows[px][t2] && !cols[py][t2] && !blocks[(px/3)*3+(py/3)][t2]
                    && dominos.find(make_pair(min(t1, t2), max(t1, t2))) == dominos.end()) {
                        board[x][y] = t1+1;
                        board[px][py] = t2+1;
                        rows[x][t1] = true;
                        cols[y][t1] = true;
                        blocks[(x/3)*3+(y/3)][t1] = true;
                        rows[px][t2] = true;
                        cols[py][t2] = true;
                        blocks[(px/3)*3+(py/3)][t2] = true;
                        dominos.insert(make_pair(min(t1, t2), max(t1, t2)));
                        if(solve(board, idx+1)) {
                            return true;
                        }
                        board[x][y] = 0;
                        board[px][py] = 0;
                        rows[x][t1] = false;
                        cols[y][t1] = false;
                        blocks[(x/3)*3+(y/3)][t1] = false;
                        rows[px][t2] = false;
                        cols[py][t2] = false;
                        blocks[(px/3)*3+(py/3)][t2] = false;
                        dominos.erase(make_pair(min(t1, t2), max(t1, t2)));
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n, row, col;
    int u, v;
    string lu, lv;
    vector<vector<int> > board(9, vector<int>(9, 0));
    while(true) {
        cin >> n;
        if(n == 0) break;

        // init
        cnt ++;
        dominos.clear();
        board.assign(9, vector<int>(9, 0));
        rows.assign(9, vector<bool>(9, false));
        cols.assign(9, vector<bool>(9, false));
        blocks.assign(9, vector<bool>(9, false));

        for(int i = 0; i < n; i ++) {
            cin >> u >> lu >> v >> lv;
            row = lu[0]-'A';
            col = lu[1]-'0'-1;
            board[row][col] = u;
            u --;
            rows[row][u] = true;
            cols[col][u] = true;
            blocks[(row/3)*3+(col/3)][u] = true;

            row = lv[0]-'A';
            col = lv[1]-'0'-1;
            board[row][col] = v;
            v --;
            rows[row][v] = true;
            cols[col][v] = true;
            blocks[(row/3)*3+(col/3)][v] = true;
            
            dominos.insert(make_pair(min(u, v), max(u, v)));
        }

        for(int i = 0; i < 9; i ++) {
            cin >> lu;
            row = lu[0]-'A';
            col = lu[1]-'0'-1;
            board[row][col] = i+1;
            rows[row][i] = true;
            cols[col][i] = true;
            blocks[(row/3)*3+(col/3)][i] = true;
        }

        solve(board, 0);

    }


    return 0;
}