#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//get the biggest element.
template<typename KeyType, typename ValueType>
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>;
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  });
}
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

int main() {
  cin.tie(0);ios::sync_with_stdio(false);
  int n;
  cin >> n;
  map<ll, ll> mp;
  rep (i, n) {
    int x; cin >> x;
    ++mp[x];
  }

  ll total = 0;
  for (auto v : mp) {
    total += v.first * v.second;
  }

  int q; cin >> q;
  vector<ll> ans;
  rep (i, q) {
    ll b, c;
    cin >> b >> c;
    total -= mp[b] * b;
    total += c * mp[b];
    mp[c] += mp[b];
    mp[b] = 0;
    ans.push_back(total);
  }

  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}
