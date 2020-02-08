#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int c;
  map<int, int> cnt;

  for (int i = 0; i < N; i++) {
    cin >> c;
    cnt[c]++;
  }
  int min = N;
  int res = 0;
  for(auto i = cnt.begin(); i != cnt.end(); i++) {
    if (i->first <= i->second) {
      res += i->second - i->first;
    } else {
      res += i->second;
    }
  }
  cout << res << endl;
}
