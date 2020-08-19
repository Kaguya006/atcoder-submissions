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
vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    ll ex = 0;
    while (n % i == 0) {
      ++ex;
      n /= i;
    }
    res.push_back({i, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  ll n, p;
  cin >> n >> p;
  ll ans = 1;
  for (auto v : prime_factorize(p)) {
    ans *= pow(v.first, v.second/n);
  }
  cout << ans << endl;
  return 0;
}
