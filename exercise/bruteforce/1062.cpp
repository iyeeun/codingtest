#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxval = 0;

void learn(int idx, int k, int mask, vector<int> &words) {
    // idx : 지금 보고 있는 알파벳
    // k : 고를 수 있는 알파벳의 개수
    // mask : 지금까지 선택된 알파벳을 표현하는 비트마스크
    if(k < 0) return;
    if(idx == 26) {
        // 읽을 수 있는 단어의 수 계산
        int cnt = 0;
        for(int word : words) {
            if((word & ((1 << 26)-1-mask)) == 0) cnt ++;
        }
        if(cnt > maxval) maxval = cnt;
        return;
    }

     // 현재 idx 알파벳을 배움
    learn(idx+1, k-1, mask | (1 << idx), words);
    if(idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'i'-'a' && idx != 'c'-'a') {
        // 배우지 않음
        learn(idx+1, k, mask, words);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    vector<int> words(n); // 각 단어의 알파벳 구성을 비트마스크로 저장하는 벡터
    for(int i = 0; i < n; i ++) {
        cin >> s;
        for(char c : s) {
            // 각 알파벳에 대한 비트마스크를 만들어서 OR 연산 수행
            // 해당 알파벳의 자리를 1로 만들어줌
            words[i] |= (1 << (c-'a')); 
        }
    }

    learn(0, k, 0, words);

    cout << maxval << "\n";

    return 0;
}