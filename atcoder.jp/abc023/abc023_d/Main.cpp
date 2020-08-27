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
  int n;
  cin >> n;
  vector<ll> h(n), s(n);
  rep (i, n) cin >> h[i] >> s[i];

  ll left = 0, right = INF;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    
    bool ok = true;
    vector<ll> t(n);
    rep (i, n) {
      if (mid < h[i]) ok = false;
      else t[i] = (mid - h[i]) / s[i];
    }
    
    sort (t.begin(), t.end());
    rep (i, n) if (t[i] < i) ok = false;
    
    if (ok) right = mid;
    else left = mid;
  }

  cout << right << endl;
  return 0;
}
