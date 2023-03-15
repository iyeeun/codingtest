#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
char alphabet[15];
bool chosen[15] = {false};

void find_pwd(int idx, int prev, string password) {
    if(idx == l) {
        // condition check & print
        int vowel = 0;
        int consonant = 0;
        for(int i = 0; i < l; i ++) {
            if(password[i] == 'a'||password[i] == 'e'||password[i] == 'i'||password[i] == 'o'||password[i] == 'u') {
                vowel ++;
            } else {
                consonant ++;
            }
        }
        if(vowel >= 1 && consonant >= 2) {
            cout << password << "\n";
        }
        return;
    }

    for(int i = prev+1; i < c; i ++) {
        if(chosen[i]) continue;
        chosen[i] = true;
        find_pwd(idx+1, i, password+alphabet[i]);
        chosen[i] = false;
    }

}

int main() {
    
    cin >> l >> c;

    for(int i = 0; i < c; i ++) {
        cin >> alphabet[i];
    }

    sort(alphabet, alphabet+c);

    find_pwd(0, -1, "");

    return 0;
}