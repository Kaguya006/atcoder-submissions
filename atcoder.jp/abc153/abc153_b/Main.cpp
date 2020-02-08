#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;

  int x;
  for (int i = 0; i < N && H > 0; i++) {
    cin >> x;
    H = H - x;
  }
  if (H <= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
