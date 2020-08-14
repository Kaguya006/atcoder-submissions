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
  int n, cnt;
  cin >> n >> s;
  cnt = 0;
  for (int i = 0; i < 1000; i++) {
    int c[3] = {i / 100, i / 10 % 10, i % 10};
    int f = 0;
    for (int j = 0; j < n; j++) {
      if (c[f] == s[j] - '0') f++;
      if (f == 3) break;
    }
    if (f == 3) cnt++;
  }

  cout << cnt << endl;
  return 0;
}
