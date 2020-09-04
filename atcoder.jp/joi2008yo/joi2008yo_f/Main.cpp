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
struct edge { int to, cost; };
vector<vector<edge>> g(10000000);
vector<ll> d(1000);
int N, K;

ll dijkistra(int s, int dist) {
  priority_queue<P, vector<P>, greater<P>> que;
  que.push({0, s});
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  
  while(!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    rep (i, g[v].size()) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
	d[e.to] = d[v] + e.cost;
	que.push({d[e.to], e.to});
      }
    }
  }

  if (d[dist] == INF) return -1;
  else return d[dist];
}

int main() {
  cin >> N >> K;
  vector<int> ans;
  rep (i, K) {
    int q; cin >> q;
    if (q == 0) {
      int a, b; cin >> a >> b;
      ans.push_back(dijkistra(a, b));
    } else {
      int x, y, z; cin >> x >> y >> z;
      edge e;
      e.to = y; e.cost = z;
      g[x].push_back(e);
      e.to = x; e.cost = z;
      g[y].push_back(e);
    }   
  }
  for (auto v : ans) cout << v << endl;
  return 0;
}
