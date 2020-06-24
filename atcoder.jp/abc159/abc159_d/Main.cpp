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
  int n;
  cin >> n;
  map<ll, ll> mi;
  vector<ll> a(n);
  rep (i, n) {
    int x;
    cin >> x;
    a[i] = x;
    ++mi[x];
  }

  ll tmp = 0;
  for (auto v : mi) {
    ll x = v.second;
    tmp += x * (x - 1) / 2;
  }

  for (int i = 0; i < n; i++) {
    ll x = mi[a[i]];
    cout << tmp - (x * (x - 1) / 2) + ((x - 1) * (x - 2) / 2) << endl;
  }

  return 0;
}
