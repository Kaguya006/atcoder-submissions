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
  vector<int> a(100);
  rep (i, n) {
    int x;
    cin >> x;
    --x;
    a[x] += 1;
  }

  int ans = 1e6;
  int total;
  rep (i, 100) {
    total = 0;
    rep (j, 100) {
      if (a[j] == 0) continue;
      total += pow(i - j, 2) * a[j];
    }
    ans = min(ans, total);
  }

  cout << ans << endl;
  return 0;
}
