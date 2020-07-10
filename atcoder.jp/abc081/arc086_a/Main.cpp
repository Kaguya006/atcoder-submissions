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
  int n, k;
  cin >> n >> k;
  map <int, int> mii;
  rep (i, n) {
    int x;
    cin >> x;
    mii[x]++;
  }

  vector<P> top_k;
  for (auto v : mii) {
      top_k.push_back(make_pair(v.second, v.first));
  }
  sort(top_k.rbegin(), top_k.rend());

  //for (auto v : top_k) {
  //  cout << v.first << "    " << v.second << endl;
  //}

  int ans = 0;
  if (mii.size() > k) {
    for (int i = k; i < top_k.size(); i++) ans += top_k[i].first;
  }

  cout << ans << endl;
  return 0;
}
