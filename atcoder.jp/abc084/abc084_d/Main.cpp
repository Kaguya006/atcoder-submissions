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

bool is_prime(ll a) {
  if (a < 2) return false;
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int Q;
  cin >> Q;
  const int maxn = 1e5 + 10;
  vector<int> a(maxn);
  for (int i = 1; i < maxn; i++) {
    if (i % 2 != 0 && is_prime(i) && is_prime((i + 1) / 2)) {
      a[i] = a[i - 1] + 1;
    } else {
      a[i] = a[i - 1];
    }
  }

  vector<int> ans;
  rep (i, Q) {
    int l, r; cin >> l >> r;
    ans.push_back(a[r] - a[l - 1]);
  }
  for (auto v : ans) cout << v << endl;
  return 0;
}
