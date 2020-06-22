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

ll mx = 0;
int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  for (int d = 1; d <= 10; d++) {
    ll p = (x - (b * d) ) / a;
    int size = to_string(p).size();
    if (size > d || size == 10) {
      mx = max(mx, (ll)pow(10, d - 1));
    } else {
      mx = max(mx, p);
    }
  }

  cout << mx << endl;
  return 0;
}
