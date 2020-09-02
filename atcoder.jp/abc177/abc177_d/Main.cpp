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
struct UnionFind {
  vector<int> a;
  UnionFind(int n) : a(n) {
    for(int i = 0; i < n; i++) a[i] = i;
  }

  int root(int x) { 
    if (a[x] == x) return x;
    return a[x] = root(a[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    a[rx] = ry;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  } 
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep (i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
  }

  map<int, int> mp;
  rep (i, n) {
    mp[uf.root(i)]++;
  }

  vector<int> a;
  for (auto v : mp) a.push_back(v.second);
  sort(a.begin(), a.end());
  ll minus = 0;
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    a[i] -= minus;
    minus += a[i];
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
