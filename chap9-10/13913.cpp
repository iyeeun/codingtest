#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

  int s, e;
  cin >> s >> e;

  vector<int> time(2*max(s, e)+1, -1);
  vector<int> prev(2*max(s, e)+1, -1);
  queue<int> q;

  q.push(s);
  time[s] = 0;

  while(!q.empty()) {
    int fr = q.front();
    q.pop();
    int frtime = time[fr];

    if(fr >= 0 && time[fr-1] == -1) {
      q.push(fr-1);
      time[fr-1] = frtime + 1;
      prev[fr-1] = fr;
    }

    if(fr <= 2*max(s, e) && time[fr+1] == -1) {
      q.push(fr+1);
      time[fr+1] = frtime + 1;
      prev[fr+1] = fr;
    }

    if(2*fr >= 0 && 2*fr <= 2*max(s, e) && time[2*fr] == -1) {
      q.push(2*fr);
      time[2*fr] = frtime + 1;
      prev[2*fr] = fr;
    }
  }

  cout << time[e] << endl;

  stack<int> st;
  st.push(e);
  
  while(true) {
    int p = prev[st.top()];
    if(p == -1) break;
    st.push(p);
    if(p == s) break;
  }

  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << "\n";

  return 0;
}