#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//Get the highest value and key from a map.
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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll mini = INF;
  for (int i = 0; i < n; i++) {
    if (i == 0) continue;
    vector<int> b(n);
    vector<int> c(n);
    copy(a.begin(), a.begin() + i, b.begin());
    copy(a.begin() + i, a.end(), c.begin());
    ll dis = abs(accumulate(b.begin(), b.end(), 0) - accumulate(c.begin(), c.end(), 0)); 
    mini = min(mini, dis);
  }

  cout << mini << endl;
  return 0;
}
