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
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = abs(a[0] - a[1]);
  for (int i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
    chmin(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
  }

  cout << dp[n - 1] << endl;
  return 0;
}
