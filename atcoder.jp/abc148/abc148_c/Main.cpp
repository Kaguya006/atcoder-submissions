#include <bits/stdc++.h>
using namespace std;

vector<int> S1;

int Euclidean(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    int x = a % b;
    return Euclidean(max(b,x), min(b,x));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long A, B;
  cin >> A >> B;

  long long res = Euclidean(max(A,B), min(A,B));
  res = (A * B) / res;
  cout << res << '\n';
  return 0;
}
