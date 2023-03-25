#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    char arr[4][4];
    string str;
    int maxsum = -1;
    cin >> n >> m;

    for(int i = 0; i < n; i ++) {
        cin >> str;
        for(int j = 0; j < m; j ++) {
            arr[i][j] = str[j];
        }
    }
    
    for(int i = 0; i < (1 << (n*m)); i ++) {
        int sum = 0;
        string tmpsum = "";

        // 1 -> -, 0 -> |
        for(int j = 0; j < n; j ++) {
            for(int t = 0; t < m; t ++) {
                if(i & (1 << (j*m+t))) {
                    tmpsum += arr[j][t];
                } else {
                    if(tmpsum != "") sum += stoi(tmpsum);
                    tmpsum = "";
                }
            }
            if(tmpsum != "") sum += stoi(tmpsum);
            tmpsum = "";
        }

        tmpsum = "";
        for(int j = 0; j < m; j ++) {
            for(int t = 0; t < n; t ++) {
                if(i & (1 << (t*m+j))) {
                    if(tmpsum != "") sum += stoi(tmpsum);
                    tmpsum = "";
                } else {
                    tmpsum += arr[t][j];
                }
            }
            if(tmpsum != "") sum += stoi(tmpsum);
            tmpsum = "";
        }

        if(sum > maxsum) maxsum = sum;
    }

    cout << maxsum << "\n";

    return 0;
}