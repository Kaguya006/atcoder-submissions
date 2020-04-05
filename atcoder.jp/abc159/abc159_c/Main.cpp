#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
  double l;
  cin >> l;

  double x = l / 3;
  double ans = 1;
  for (int i = 0; i < 3; i++) ans *= x;
  cout << fixed << setprecision(15) << ans << endl;
}
