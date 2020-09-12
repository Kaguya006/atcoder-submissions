#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;

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
  ll N;
  cin >> N;

  int cnt = 0;
  for (auto v : prime_factorize(N)) {
    //cout << v.first << " " << v.second << endl;
    int n = 1;
    while (v.second - n >= 0) {
      cnt++;
      v.second -= n;
      n++;
    }
  }

  cout << cnt << endl;
  return 0;
}
