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
  int t, n, m;
  cin >> t >> n;
  queue<int> takoyaki;
  rep (i, n) {
    int x;
    cin >> x;
    takoyaki.push(x);
  }
  cin >> m;
  queue<int> customers;
  rep (i, m) {
    int y;
    cin >> y;
    customers.push(y);
  }

  bool ok = false;
  int must = m;
  while (!takoyaki.empty() && !ok) {
    if (takoyaki.front() - customers.front() > 0 || customers.front() - takoyaki.front() > t) {
      takoyaki.pop();
    } else {
      takoyaki.pop();
      customers.pop();
    }
    if (customers.empty()) {
      ok = true;
    }
  }

  if (ok) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
