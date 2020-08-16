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
  vector<int> s(n);
  int cnt = 0;
  rep (i, n) cin >> s[i];
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
	if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) {
	  if (s[i] < s[j] + s[k] && s[j] < s[i] + s[k] && s[k] < s[i] + s[j])cnt++;
	}
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
