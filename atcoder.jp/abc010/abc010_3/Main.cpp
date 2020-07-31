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
  int ax, ay, bx, by, t, v;
  cin >> ax >> ay >> bx >> by >> t >> v;
  int n;
  cin >> n;
  vector<vector<int>>Girls(n);
  bool ok = true;
  rep (i, n) {
    int x, y;
    cin >> x >> y;
    
    if ((x == ax && y == ay) || (x == bx && y == by)) {
      ok = false;
    }
    
    Girls[i].push_back(x);
    Girls[i].push_back(y);
  }

  if (ok) {
    int maxdis = t * v;
    for (auto v : Girls) {
      long double dis = sqrt(pow(ax - v[0], 2) + pow(ay - v[1], 2));
      dis += sqrt(pow(bx - v[0], 2) + pow(by - v[1], 2));
      if (dis <= maxdis + 0.005) {
	cout << "YES" << endl;
	return 0;
      }
    }
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
