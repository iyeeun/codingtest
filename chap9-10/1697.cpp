#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int s, e;
  cin >> s >> e;

  vector<int> time(2*max(s, e)+1, -1);
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
    }

    if(fr <= 2*max(s, e) && time[fr+1] == -1) {
      q.push(fr+1);
      time[fr+1] = frtime + 1;
    }

    if(2*fr >= 0 && 2*fr <= 2*max(s, e) && time[2*fr] == -1) {
      q.push(2*fr);
      time[2*fr] = frtime + 1;
    }
  }

  cout << time[e] << endl;

  return 0;
}