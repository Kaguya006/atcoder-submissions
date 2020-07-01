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
  int n;
  cin >> n;

  vector<int> mode_a(1e6);
  vector<int> mode_b(1e6);

  rep (i, n) {
    int x;
    cin >> x;

    if (i % 2 == 0) {
      mode_a[x]++;
    } else {
      mode_b[x]++;
    }
  }

  int max_a = max_element(mode_a.begin(), mode_a.end()) - mode_a.begin();
  int max_b = max_element(mode_b.begin(), mode_b.end()) - mode_b.begin();

  ll ans = n;
  if (max_a == max_b) {
    sort(mode_a.rbegin(), mode_a.rend());
    sort(mode_b.rbegin(), mode_b.rend());
    ans -= max(mode_a[0] + mode_b[1], mode_b[0] + mode_a[1]);
  } else {
    ans -= (mode_a[max_a] + mode_b[max_b]);
  }

  cout << ans << endl;

  //rep (i, 10) cout << mode_a[i];
  //cout << endl;
  //rep (i, 10) cout << mode_b[i];

  return 0;
}
