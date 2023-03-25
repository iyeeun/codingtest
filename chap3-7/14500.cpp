#include <iostream>
#include <vector>

using namespace std;

int blockcoor[19][3][2] = 
{
    {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {2, 0}, {3, 0}},
    {{0, 1}, {1, 0}, {1, 1}},
    {{1, 0}, {2, 0}, {2, 1}},
    {{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {0, 2}, {-1, 2}},
    {{-1, 0}, {0, 1}, {0, 2}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{1, 0}, {0, 1}, {0, 2}},
    {{0, 1}, {0, 2}, {1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},
    {{1, 0}, {1, -1}, {2, -1}},
    {{0, 1}, {-1, 1}, {-1, 2}},
    {{0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {2, 0}, {1, -1}},
    {{0, 1}, {0, 2}, {-1, 1}},
    {{0, 1}, {0, 2}, {1, 1}}
};

int main() {
    int n, m;
    long res = 0, tmp = 0;
    cin >> n >> m;
    vector<vector<int> > board(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int t = 0; t < 19; t ++) {
                bool possible = true;
                tmp = board[i][j];
                for(int h = 0; h < 3; h ++) {
                    int x = i+blockcoor[t][h][0];
                    int y = j+blockcoor[t][h][1];
                    if(0 <= x && x < n && 0 <= y && y < m) {
                        tmp += board[x][y];
                    } else {
                        possible = false;
                        break;
                    }
                }
                if(possible && tmp > res) res = tmp;
            }
        }
    }

    cout << res << endl;

    return 0;
}