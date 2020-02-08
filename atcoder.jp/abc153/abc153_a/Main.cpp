#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, A;
  cin >> H >> A;
  int cnt = 0;
  while (true) {
    if (H < 1) break;
    H = H - A;
    cnt++;
  }
  cout << cnt << endl;
}
