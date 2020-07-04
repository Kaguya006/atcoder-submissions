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
  vector<ll> alp(5);
  rep (i, n) {
    string s;
    cin >> s;
    if (s[0] == 'M') alp[0]++;
    if (s[0] == 'A') alp[1]++;
    if (s[0] == 'R') alp[2]++;
    if (s[0] == 'C') alp[3]++;
    if (s[0] == 'H') alp[4]++;
  }

  ll ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += alp[i] * alp[j] * alp[k];
      }
    }
  }

  cout << ans << endl;
  return 0;
}
