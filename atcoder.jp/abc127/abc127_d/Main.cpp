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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  sort(a.begin(), a.end());

  vector<pair<ll, ll>> vpi;
  rep (i, m) {
    int b, c;
    cin >> b >> c;
    vpi.push_back(make_pair(c, b));
  }

  sort(vpi.rbegin(), vpi.rend());
 
  int i = 0;
  ll ans = 0;
  bool ok = true;
  for (auto v : vpi) {
    if (ok) {
      int j = upper_bound(a.begin() + i, a.end(), v.first) - a.begin();
      j = j - i;
      if (j == 0) {
	ok = false;
      } else {
	if (j <= v.second) {
	  ans += v.first * j;
	  i += j;
	} else {
	  ans += v.first * v.second;
	  i += v.second;
	}
      }
    }
  }
  ans += accumulate(a.begin() + i, a.end(), 0LL);

  cout << ans << endl;
  return 0;
}
