#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;

  int res = 0;
  res += (X / 500) * 1000;
  X %= 500;
  res += (X /= 5) * 5;

  cout << res << endl;

  return 0;
}
