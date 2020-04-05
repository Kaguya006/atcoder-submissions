#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, ans;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans++;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
