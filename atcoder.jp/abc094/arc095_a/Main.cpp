#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];
  vector<int> sorted = a;
  sort(sorted.begin(), sorted.end());
  for (auto v : a) {
    if (v <= sorted[n / 2 - 1]) {
      cout << sorted[n / 2] << endl;
    } else {
      cout << sorted[n / 2 - 1] << endl;
    }
  }
  return 0;
}
