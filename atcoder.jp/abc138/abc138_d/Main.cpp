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

int n, q, a, b, p, x;
vector<vector<int>> G(1e5 * 2 + 10);
vector<ll> V(1e5 * 2 + 10);

void dfs(int p, int q) {
  for (auto next_v : G[p]) {
    if (next_v == q) continue;
    V[next_v] += V[p];
    dfs(next_v, p);
  }
}

int main() {
  cin >> n >> q;
  rep (i, n - 1) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep (i, q) {
    int pos, pts;
    cin >> pos >> pts;
    V[pos] += pts;
  }

  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << V[i] << endl;
  }
  return 0;
}
