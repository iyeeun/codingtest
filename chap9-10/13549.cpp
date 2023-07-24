#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;

  vector<int> time(200001, -1);
  deque<int> d;

  d.push_back(n);
  time[n] = 0;

  while(!d.empty()) {
    int fr = d.front();
    d.pop_front();

    if(fr == k) break;

    if(2*fr < 200000) {
      if(time[2*fr] == -1) {
        d.push_front(2*fr);
        time[2*fr] = time[fr];
      }
    }
    if(fr+1 < 200000) {
      if(time[fr+1] == -1) {
        d.push_back(fr+1);
        time[fr+1] = time[fr] + 1;
      }
    }
    if(fr-1 >= 0) {
      if(time[fr-1] == -1) {
        d.push_back(fr-1);
        time[fr-1] = time[fr] + 1;
      }
    }
  }

  cout << time[k] << "\n";

  return 0;
}