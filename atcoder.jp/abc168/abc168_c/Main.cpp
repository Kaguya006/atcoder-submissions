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

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;
int main() {
  double A, B, H, M;
  cin >> A >> B >> H >> M;
  double ang_m = M * (360.0 / 60.0);
  H += (M / 60.0);
  double ang_h = H * 360.0 / 12.0;
  double dis_ang = abs(ang_h - ang_m);
  double x = A*A + B*B - (2 * A * B)*cos(degreeToRadian(dis_ang));
  cout << fixed << setprecision(15);
  cout << sqrt(x) << endl;
  return 0;
}
