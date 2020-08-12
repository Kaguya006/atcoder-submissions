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
  string s;
  cin >> s;
  ll ans = -INF;

  for (int i = 0; i < s.size(); i++) {
    int cnt = 0;
    for (int j = i; j < s.size(); j++) {
      if (s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T') cnt++;
      else break;
    }
    ans = max(ans, (ll)cnt);
  }
  cout << ans << endl;
  return 0;
}
