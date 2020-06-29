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
  map<int, int> mp;
  vector<ll> vl; 
  rep (i, n) {
    int x; cin >> x;
    ++mp[x];
  }

  for (auto v : mp) {
    if (v.second >= 2) {
      if (v.second >= 4) {
        vl.push_back(v.first);
      }
      vl.push_back(v.first);
    }
  }

  if (vl.size() >= 2) {
    sort(vl.rbegin(), vl.rend());
    cout << vl[0] * vl[1] << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
