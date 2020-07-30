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

int n, k;
bool ok = true;
vector<vector<int>>a(10);

void dfs(int row, int now) {
  if (row == n - 1) {
    for (int j = 0; j < k; j++) {
      int tmp = now ^ a[row][j];
      if (tmp == 0) ok = false;
    }
    return;
  }
  
  for (int j = 0; j < k; j++) {
    dfs(row + 1, now ^ a[row][j]);
  }
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> n >> k;
  rep (i, n) {
    rep (j , k) {
      int t;
      cin >> t;
      a[i].push_back(t);
    }
  }

  dfs(0, 0);
  if (ok) {
    cout << "Nothing" << endl;
  } else {
    cout << "Found" << endl;
  }
  return 0;
}
