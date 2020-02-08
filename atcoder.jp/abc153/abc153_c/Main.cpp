#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  vector<ll> H;

  cin >> N >> K;

  ll x; 
  for (int i = 0; i < N; i++) {
    cin >> x;
    H.push_back(x);
  }

  sort(H.rbegin(), H.rend());

  for (int i = 0; i < K && i < H.size(); i++) {
    H[i] = -1; //death
  }

  ll cnt = 0;
  for (int i = 0; i < H.size(); i++) {
    if (H[i] != -1) {
      cnt += H[i];
    }
  }
  cout << cnt << endl;

  return 0;
}
