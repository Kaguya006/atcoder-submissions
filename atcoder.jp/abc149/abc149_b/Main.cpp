#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  long long A, B, K;
  cin >> A >> B >> K;
  A = A - K;
  if (A < 0) {
    B = B + A;
  }
  if (A < 0) A = 0;
  if (B < 0) B = 0;
  cout << A << " " << B << '\n';
}
