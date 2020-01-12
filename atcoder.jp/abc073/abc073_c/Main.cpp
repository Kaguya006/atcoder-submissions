#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  map<int, int> m;
  int count = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (m.find(a) == m.end()) {
      m[a] = 1;
      count++;
    } else {
      if (m[a] == 0) {
        m[a] = 1;
        count++;
      } else {
        m[a] = 0;
        count--;
      }
    }
  }
  cout << count << '\n';

  return 0;
}
