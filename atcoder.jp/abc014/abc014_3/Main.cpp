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

const int maxn = 1e6 + 10;
int main() {
  int n;
  cin >> n;
  vector<int> vi(maxn);
  rep (i, n) {
    int a, b;
    cin >> a >> b;
    vi[a] += 1;
    vi[b + 1] -= 1;
  }

  vector<int> ans(maxn);
  ans[0] = 0;
  rep (i, maxn) {
    ans[i + 1] = ans[i] + vi[i];
  }

  cout << *max_element(ans.begin(), ans.end()) << endl;
  return 0;
}
