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

int n, m;
bool ok = false;
vector<vector<int>>graph(300000);

void dfs(int now, int time, int p) {
  if (time > 2) return;
  if (now == n) ok = true;

  for (auto next_v : graph[now]) {
    if (next_v == p) continue;
    dfs(next_v, time + 1, now);
  }
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> n >> m;
  rep (i, m) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, 0, 0);

  if (ok) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
