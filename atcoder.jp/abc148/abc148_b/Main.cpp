#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;

  for (int i = 0; i < N; i++) {
    cout << S[i] << T[i];
  }
  cout << '\n';
}
