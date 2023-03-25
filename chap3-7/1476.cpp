#include <iostream>

using namespace std;

int main() {
    int e, s, m, year = 0;
    cin >> e >> s >> m;

    for(int i = 1; i <= 7980; i ++) {
        if(i % 15 == e % 15 && i % 28 == s % 28 && i % 19 == m % 19) {
            year = i;
            break;
        }
    }

    cout << year << endl;

    return 0;
}