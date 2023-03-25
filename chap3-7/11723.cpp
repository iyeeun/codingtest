#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int m, num;
    string cmd;
    cin >> m;

    int s = 0;

    for(int i = 0; i < m; i ++) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> num;
            s = s | (1 << num);
        } else if(cmd == "remove") {
            cin >> num;
            s = s & ~(1 << num);
        } else if(cmd == "check") {
            cin >> num;
            if((s & (1 << num))) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if(cmd == "toggle") {
            cin >> num;
            s = s ^ (1 << num);
        } else if(cmd == "all") {
            s = 0b111111111111111111111;
        } else if(cmd == "empty") {
            s = 0;
        }
    }

    return 0;
}