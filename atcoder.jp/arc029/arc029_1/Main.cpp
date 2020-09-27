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
int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  int sum = accumulate(a.begin(), a.end(), 0);
  if (n == 1) {
    cout << sum << endl;
    return 0;
  }

  int ans = 1e9;
  int ans_v;
  for (int bit = 1; bit < (1 << n); bit++) {
    if (bit == 1 << n - 1) continue;
    int x = 0;
    rep (j, n) if (bit & 1 << j) x += a[j];
    int y = abs(sum - 2*x);
    if (y < ans) {
      ans = y;
      ans_v = max(sum - x, x);
    }          
  }
  cout << ans_v << endl;
  return 0;
}
