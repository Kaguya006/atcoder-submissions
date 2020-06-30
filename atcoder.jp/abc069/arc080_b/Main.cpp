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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> g(h, vector<int>(w));

  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  int i = 0, j = 0;
  int color = 1;
  bool rev = false;
  for (auto v : a) {
    int c = v;
    while (c) {
      g[i][j] = color;
      //printf("[%d][%d] = %d]\n", i, j, color);
      if (rev) --j;
      else ++j;
      if (j == w) {
        rev = true;
        ++i;
        --j;
      } else if (j == -1) {
        rev = false;
        ++i;
        ++j;
      }
      --c;
    }
    ++color;
  }

  for (int p = 0; p < h; p++) {
    for (int q = 0; q < w; q++) {
      cout << g[p][q] << " ";
    }
    cout << endl;
  }

  return 0;
}
