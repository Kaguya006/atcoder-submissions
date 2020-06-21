#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//get the biggest element.
template<typename KeyType, typename ValueType>
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>;
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  });
}
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> p(n, vector<int>(n, -1));
  rep (i, n) {
    int a;
    cin >> a;
    rep (j, a) {
      int x, y;
      cin >> x >> y;
      --x;
      p[i][x] = y;
    }
  }

  int ans = 0;
  for (int bit = 0; bit < 1 << n; bit++) {
    bool ok = true;
    vector<int> truth(n, -1);
    for (int i = 0; i < n; i++) {
      if (bit & 1 << i) {
        for (int j = 0; j < n; j++) {
          if (p[i][j] == -1) continue;
          if (p[i][j] == 0) {
            if (bit & 1 << j) ok = false;
          } else {
            if (!(bit & 1 << j)) ok = false;
          }
          if (truth[j] == -1) {
            truth[j] = p[i][j];
          } else {
            if (truth[j] != p[i][j]) ok = false;
          }
        }
      }
    }
    //if (ok) printf("bit = %d, popcount = %d\n", bit, __builtin_popcount(bit));
    if (ok) ans = max(ans, __builtin_popcount(bit));
  }

  cout << ans << endl;

  return 0;
}
