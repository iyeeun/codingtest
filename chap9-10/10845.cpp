#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    int n;
    cin >> n;
    string cmd;
    queue<int> q;

    for(int i = 0; i < n; i ++) {
        cin >> cmd;
        if(cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if(cmd == "pop") {
            if(!q.empty()) {
                int num = q.front();
                q.pop();
                cout << num << "\n";
            } else {
                cout << "-1\n";
            }
        } else if(cmd == "front") {
            if(!q.empty()) {
                int num = q.front();
                cout << num << "\n";
            } else {
                cout << "-1\n";
            }
        } else if(cmd == "back") {
            if(!q.empty()) {
                int num = q.back();
                cout << num << "\n";
            } else {
                cout << "-1\n";
            }
        } else if(cmd == "size") {
            cout << q.size() << "\n";
        } else if(cmd == "empty") {
            if(q.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}