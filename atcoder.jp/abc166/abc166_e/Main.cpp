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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  map<ll, ll> cnt1;
  map<ll, ll> cnt2;

  rep (i, n) {
    cnt1[i + a[i]]++;
    cnt2[i - a[i]]++;
  }

  ll ans = 0;
  for (auto v : cnt1) {
    ans += cnt1[v.first] * cnt2[v.first];
  }

  cout << ans << endl;
  
  return 0;
}
