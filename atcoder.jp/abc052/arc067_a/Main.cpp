#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);

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

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  while (n) {
    for (auto v : prime_factorize(n--)) {
      mp[v.first] += v.second;
    }
  }

  ll ans = 1;
  for (auto v : mp) {
    ans = ans % MOD * (v.second + 1);
  }

  cout << ans % MOD << endl;

  return 0;
}
