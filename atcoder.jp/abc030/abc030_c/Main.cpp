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
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m);
  stack<int> a, b;
  int x, y;
  cin >> x >> y;
  rep (i, n) cin >> A[i];
  rep (i, m) cin >> B[i];
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  rep (i, n) a.push(A[i]);
  rep (i, m) b.push(B[i]);

  ll ans = 0;
  bool nowA = true;
  while (!a.empty() && !b.empty()) {
    if (nowA) {
      int start = a.top();
      while (start + x > b.top()) {
	b.pop();
	if (b.empty()) break;
      }
      nowA = false;
      a.pop();
    } else {
      int start = b.top();
      while (start + y > a.top()) {
	a.pop();
	if (a.empty()) break;
      }
      nowA = true;
      b.pop();
      ans++;
    }
  }
  if (!nowA && !b.empty()) ans++;
  
  cout << ans << endl;
  return 0;
}
