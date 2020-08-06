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
  vector<vector<int>> G(n);
  rep (i, m) {
    int a, b;
    cin >> a >> b;
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    map<int, int> rel;
    rel[i] = 1;
    int ans = 0;
    for (auto v : G[i]) rel[v] = 1;
    for (auto v : G[i]) {
      for (auto ff : G[v]) {
	if (rel[ff] != 1) {
	  rel[ff] = 1;
	  ans++;
	}
      }
    }

    cout << ans << endl;
  }
  return 0;
}
