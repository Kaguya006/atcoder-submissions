#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  do {
    a -= d;
    c -= b;
  } while (a > 0 && c > 0);

  
  if (a <= 0 && c <= 0) {
    cout << "Yes" << endl;
  } else {
    if (a < c) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
