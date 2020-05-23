#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n) {
    rep(i, n) par[i] = i;
  }

  void unite(int a, int b) {
    int ra = root(a);
    int rb= root(b);
    if (ra == rb) return;
    par[ra] = rb;
  }

  int root(int a) {
    if (par[a] == a) return a;
    return par[a] = root(par[a]);
  }

  bool same(int a, int b) {
    int ra = root(a);
    int rb = root(b);

    return ra == rb;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> nums(n);
  UnionFind uf(n);
  rep(i, n) cin >> nums[i];
  rep(i, m) {
    int x, y;

    cin >> x >> y;
    uf.unite(--x, --y);
  }

  int ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (uf.same(i, --nums[i])) ++ans;
  }

  cout << ans << endl;

  
  return 0;
}
