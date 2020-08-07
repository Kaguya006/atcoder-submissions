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

  vector<vector<ll>>dis(n, vector<ll>(n, INF));
  rep (i, m) {
    int a, b, t;
    cin >> a >> b >> t;
    --a; --b;
    dis[a][b] = t;
    dis[b][a] = t;
  }
  rep (i, n) dis[i][i] = 0;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  ll ans = INF;
  for (auto v : dis) {
    ans = min(ans, *max_element(v.begin(), v.end()));
  }

  cout << ans << endl;
  return 0;
}
