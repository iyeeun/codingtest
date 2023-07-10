#include <iostream>
#include <string>
#include <vector>

using namespace std;

void draw(int num, int idx, int width, int height, vector<vector<int> > &screen) {
    if(num == 0) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx] = 1; // |
            screen[i][idx+width-1] = 1;
        }

    } else if(num == 1) {
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 2) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height/2][idx+i] = -1;
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height/2; i ++) {
            screen[i][idx+width-1] = 1;
        }
        for(int i = height/2+1; i < height-1; i ++) {
            screen[i][idx] = 1;
        }
    } else if(num == 3) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height/2][idx+i] = -1;
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 4) {
        for(int i = 1; i < width-1; i ++) {
            screen[height/2][idx+i] = -1;
        }
        for(int i = 1; i < height/2; i ++) {
            screen[i][idx] = 1;
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 5) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height/2][idx+i] = -1;
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height/2; i ++) {
            screen[i][idx] = 1;
        }
        for(int i = height/2+1; i < height-1; i ++) {
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 6) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height/2][idx+i] = -1;
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx] = 1;
        }
        for(int i = height/2+1; i < height-1; i ++) {
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 7) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 8) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height/2][idx+i] = -1;
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            screen[i][idx] = 1;
            screen[i][idx+width-1] = 1;
        }
    } else if(num == 9) {
        for(int i = 1; i < width-1; i ++) {
            screen[0][idx+i] = -1; // -
            screen[height/2][idx+i] = -1;
            screen[height-1][idx+i] = -1;
        }
        for(int i = 1; i < height-1; i ++) {
            if(i == height/2) continue;
            if(i < height/2) screen[i][idx] = 1;
            screen[i][idx+width-1] = 1;
        }
    }
}

int main() {
    int s;
    string n;
    cin >> s >> n;

    int width = s+2;
    int height = 2*s + 3;

    vector<vector<int> > screen(height, vector<int>(n.length() * width + n.length()-1, 0));

    for(int i = 0; i < n.length(); i ++) {
        draw(n[i]-'0', i*(width+1), width, height, screen);
    }
    
    for(int i = 0; i < height; i ++) {
        for(int j = 0; j < screen[0].size(); j ++) {
            if(screen[i][j] == 0) cout << " ";
            else if(screen[i][j] < 0) cout << "-";
            else if(screen[i][j] > 0) cout << "|";
        }
        cout << "\n";
    }


    return 0;
}