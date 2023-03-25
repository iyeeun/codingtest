#include <iostream>
#include <string>

using namespace std;

char signlst[9];
bool chosen[10] = {false};
string maxnum;
string minnum;

void find_nums(int idx, int k, string str, int prev) {
    if(str.length() == k+1) {
        if(str > maxnum) maxnum = str;
        if(str < minnum) minnum = str;
        return;
    }

    if(idx == 10) return;

    for(int i = 0; i < 10; i ++) {
        if(chosen[i]) continue;
        if(idx == 0) {
            chosen[i] = true;
            find_nums(idx+1, k, str+to_string(i), i);
            chosen[i] = false;
        } else {
            if(signlst[idx-1] == '<') {
                if(prev < i) {
                    chosen[i] = true;
                    find_nums(idx+1, k, str+to_string(i), i);
                    chosen[i] = false;
                }
            } else {
                if(prev > i) {
                    chosen[i] = true;
                    find_nums(idx+1, k, str+to_string(i), i);
                    chosen[i] = false;
                }
            }
        }
    }
}

int main() {
    int k;
    cin >> k;

    maxnum = "";
    minnum = "";

    for(int i = 0; i < k; i ++) {
        char tmp;
        cin >> tmp;
        signlst[i] = tmp;

        maxnum += '0';
        minnum += '9';
    }

    maxnum += '0';
    minnum += '9';

    find_nums(0, k, "", -1);

    cout << maxnum << endl;
    cout << minnum << endl;

    return 0;
}