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
  vector<int> a(n + 1), b(n);
  rep (i, n + 1) cin >> a[i];
  rep (i, n) cin >> b[i];

  ll cnt = 0;
  int dis = 0;
  rep (i, n) {
    if (dis < a[i]) {
      a[i] -= dis;
      cnt += dis;
    } else {
      cnt += a[i];
      a[i] = 0;      
    }
    dis = 0;

    
    if (b[i] > a[i]) {
      cnt += a[i];
      dis = b[i] - a[i];
    } else cnt += b[i];

    if (i == n - 1) cnt += min(dis, a[i + 1]);
  }
  

  cout << cnt << endl;
  return 0;
}
