#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1, 1);

  for (int i = 2; i < n + 1; i++) {
    int mp = i;
    while (mp < n + 1) {
      ++a[mp];
      mp += i;
    }
  }

  ll ans = 0;
  for (ll i = 1; i < n + 1; i++) {
    ans += i * a[i];
  }

  cout << ans << endl;
  return 0;
}
