#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;


  X -= 1;
  Y -= 1;
  int cnt[N];
  for (int i = 0; i < N; i++) cnt[i] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int dist = j - i;
      dist = min(dist, min(abs(i - X) + abs(j - Y) + 1, abs(j - X) + abs(i - Y) + 1));
      cnt[dist] += 1;
    }
  }

  for (int i = 1; i < N; i++) {
    cout << cnt[i] << endl;
  }
}
