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
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(13);
  rep (i, M) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    A[x].push_back(y);
    A[y].push_back(x);
  }

  ll ans = -INF;
  rep (i, 1 << N) {
    vector<int>rel;    
    rep (j, N) if (i & 1 << j) rel.push_back(j);
    bool ok = true;
    for (auto v : rel) {
      for (auto vv: rel) {
	if (vv == v || find(A[v].begin(), A[v].end(), vv) != A[v].end()) continue;
	ok = false;
      }
    }
    if (ok) ans = max(ans, (ll)__builtin_popcount(i));
  }

  cout << ans << endl;
  return 0;
}
