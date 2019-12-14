#include <bits/stdc++.h>

using namespace std;
int main() {
  long long k;
  string s;

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  cin >> k;

  int n = (int) s.size();
  if (s == string(n, s[0])) {
    cout << n * k / 2 << '\n';
  } else {
    int ans1 = 0;
    for (int i = 0; i+1 < n; i++) {
      if (s[i % n] == s[(i + 1) % n]) {
        ++i;
        ++ans1;
      }
    }
    int ans2 = 0;
    for (int i = 0; i + 1 < 2 * n; i++) {
      if (s[i % n] == s[(i + 1) % n]) {
        ++i;
        ++ans2;
      }
    }
    cout << ans1 + (ans2 - ans1)*(k-1) << '\n';
  }
  return 0;
}
