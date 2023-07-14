#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    char alpha[10];
    for(int i = 0; i < n; i ++) {
        cin >> words[i];
        for(int j = 0; j < words[i].length(); j ++) {
            alpha[words[i][j] - 'A'] ++;
        }
    }

    int cnt = 0;
    for(int i = 0; i < 10; i ++) {
        if(alpha[i] != 0) cnt ++;
    }
    
    vector<int> v;
    for(int i = 0; i <= cnt; i ++) {
        v.push_back(9-cnt+i);
    }

    int max = 0;
    int map[10];
    while(true) {
        if(!next_permutation(v.begin(), v.end())) break;
        int idx = 0;
        for(int i = 0; i < 10; i ++) {
            if(alpha[i] == 0) continue;
            map[i] = v[idx];
            idx ++;
        }
        int val = 0;
        for(int i = 0; i < n; i ++) {
            int tmp = 0;
            for(int j = 0; j < words[i].length(); j ++) {
                tmp *= 10;
                tmp += map[words[i][j]-'A'];
            }
            val += tmp;
        }
        if(val > max) {
            max = val;
        }
    }

    cout << max << "\n";

    return 0;
}