#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << '\n';
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
#define inf 2e9

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;
int main() {
  double L, X, Y, S, D;
  cin >> L >> X >> Y >> S >> D;
  cout << fixed << setprecision(15);

  double t1, t2;
  if (D >= S) {
    t1 = (D - S) / (X + Y);
    X < Y  ? t2 = (L - (D - S)) / (Y - X) : t2 = inf;
  } else {
    t1 = (L - (S - D)) / (X + Y);
    X < Y  ? t2 = (S - D) / (Y - X) : t2 = inf;
  }
  cout << min(t1, t2) << endl;
  return 0;
}
