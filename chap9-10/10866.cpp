#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int cmd_num = 0;
    cin >> cmd_num;
    vector<int> v;

    for(int i = 0; i < cmd_num; i ++) {
        string cmd;
        cin >> cmd;

        if(cmd == "push_front") {
            int num;
            cin >> num;
            if(v.size() == 0) {
                v.push_back(num);
            } else {
                v.push_back(0);
                for(int j = v.size()-2; j >= 0; j --) {
                    v[j+1] = v[j]; 
                }
                v[0] = num;
            }
        } else if(cmd == "push_back") {
            int num;
            cin >> num;
            v.push_back(num);
        } else if(cmd == "pop_front") {
            if(v.empty()) {
                cout << "-1\n";
            } else {
                cout << v.front() << "\n";
                if(v.size() == 1) {
                    v.pop_back();
                } else {
                    int num = v.back();
                    v.pop_back();
                    for(int j = 1; j < v.size(); j ++) {
                        v[j-1] = v[j]; 
                    }
                    v[v.size()-1] = num;
                }
            }
        } else if(cmd == "pop_back") {
            if(v.empty()) {
                cout << "-1\n";
            } else {
                cout << v.back() << "\n";
                v.pop_back();
            }
        } else if(cmd == "size") {
            cout << v.size() << "\n";
        } else if(cmd == "empty") {
            if(v.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if(cmd == "front") {
            if(v.empty()) {
                cout << "-1\n";
            } else {
                cout << v.front() << "\n";
            }
        } else if(cmd == "back") {
            if(v.empty()) {
                cout << "-1\n";
            } else {
                cout << v.back() << "\n";
            }
        }
    }

    return 0;
}