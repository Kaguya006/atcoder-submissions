#include <bits/stdc++.h>
using namespace std;

int gcdx(int a, int b) {
  if (a % b == 0) return b;
  return gcdx(b, (a % b));
}

int main() {
  int k;
  int sum = 0;
  cin >> k;

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      for (int q = 1; q <= k; q++) {
        int x = gcdx(max(i, j), min(i, j));
        sum += gcdx(max(x, q), min(x, q));
      }
    }
  }

  cout << sum << endl;

  return 0;
}
