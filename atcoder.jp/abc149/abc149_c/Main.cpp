#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  int flg;
  while (flg == 1) {
    flg = 0;
    for (int i = 2; i <= (int)sqrt(N); i++) {
      if (N % i == 0) {
        flg = 1;
        break;
      }
    }
    if (flg == 1) {
      ++N;
    } else {
      break;
    }
  }

  cout << N << '\n';
}
