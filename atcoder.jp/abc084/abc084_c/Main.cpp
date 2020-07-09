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
  vector<int> C(n - 1);
  vector<int> S(n - 1);
  vector<int> F(n - 1);
  rep (i, n - 1) {
    cin >> C[i] >> S[i] >> F[i];
  }

  for (int i = 0; i < n - 1; i++) {
    ll ans = 0;
    for (int j = i; j < n - 1; j++) {
      if (j == i) {
          ans += C[j] + S[j];
      } else {
        if (ans < S[j]) {
          ans += S[j] - ans;
        } else {
          int tmp = ans % F[j];
          if (tmp != 0) {
            ans += F[j] - tmp;
          }
        }
        ans += C[j];
      }
    }
    cout << ans << endl;
  }
  cout << 0 << endl;
  
  return 0;
}
