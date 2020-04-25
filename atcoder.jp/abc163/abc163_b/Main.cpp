#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    n -= x;
  }

  if (n < 0) {
    cout << -1 << endl;
  } else {
    cout << n << endl;
  }
  return 0;
}
