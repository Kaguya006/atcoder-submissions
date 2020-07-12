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

int solve(int x, int y, int z) {
  return (x * x) + (y * y) + (z * z) + (x * y) + (y * z) + (z * x);
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;

  vector<int> ans(1e5);

  for (int i = 1; i < 100; i++) {
    for (int j = 1; j < 100; j++) {
      for (int k = 1; k < 100; k++) {
        ans[solve(i, j, k)]++;
      }
    }
  }

  for (int i = 1; i < n + 1; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
