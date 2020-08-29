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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  rep (i, n + 1) {
    if (i == 0) a[0] = 0;
    else cin >> a[i];
  }

  vector<int> p;
  rep (i, n + 1) {
    for (int j = i; j < n + 1; j++) {
      p.push_back(a[i] + a[j]);
    }
  }
  sort(p.begin(), p.end());

  int ans = -1;
  for (auto v : p) {
    if (v > m) {
      ans = max(ans, 0);
      break;
    }
    
    int left = 0, right = p.size() - 1;
    int mid;
    while (right - left > 1) {
      mid = (left + right) / 2;
      if (v + p[mid] > m) {
	right = mid;
      } else {
	left = mid;
      }
    }
    ans = max(ans, v + p[left]);
  }
  cout << ans << endl;
  return 0;
}
