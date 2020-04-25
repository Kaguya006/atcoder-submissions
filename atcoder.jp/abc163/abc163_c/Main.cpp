#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ary[n] = {0};

  for (int i = 0; i < (n - 1); i++) {
    int x; cin >> x;
    ++ary[x - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << ary[i] << endl;
  }

  return 0;
}
