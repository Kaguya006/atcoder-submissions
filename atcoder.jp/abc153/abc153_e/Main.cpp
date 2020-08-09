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
  int h, n;
  cin >> h >> n;
  vector<vector<int>> a(n, vector<int>(2));
  rep (i, n) {
    rep (j, 2) cin >> a[i][j];
  }
  vector<vector<ll>> dp(1010, vector<ll>(10010, INF));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10010; j++) {
      int hp = j;
      if (hp <= a[i - 1][0]) {
	dp[i][j] = a[i - 1][1];
      } else {
	dp[i][j] = dp[i][hp - a[i - 1][0]] + a[i - 1][1];
      }
      chmin(dp[i][j], dp[i - 1][j]);
    }
  }

  cout << dp[n][h] << endl;
  return 0;
}
