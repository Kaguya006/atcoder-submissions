#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n, m; cin >> n >> m;
  vector<int> pref(n + 1);
  vector<pair<int, int>> data(m);
  map<int, int> cnt;
  rep (i, m) {
    int p, y; cin >> p >> y;
    data[i] = make_pair(p, y);
    cnt[y] = p;
  }
  for (auto v : cnt) {
    ++pref[v.second];
    ++cnt[v.first] = pref[v.second];
  }

  for (auto v : data) {
    printf("%06d%06d\n", v, cnt[v.second]);
  }
  return 0;
}
