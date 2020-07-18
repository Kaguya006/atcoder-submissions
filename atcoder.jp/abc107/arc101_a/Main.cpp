#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n, k;
  cin >> n >> k;

  //-30 -10 10 20 50
  vector<ll> a(n);
  rep (i, n) cin >> a[i];

  ll ans = INF;
  rep (i, n - k + 1) {
    ll left = a[i];
    ll right = a[i + (k - 1)];
    ll dis = right - left;

    ll tmp;
    if (abs(left) + dis > abs(right) + dis) {
      tmp = abs(right) + dis;
    } else {
      tmp = abs(left) + dis;
    }

    ans = min(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
