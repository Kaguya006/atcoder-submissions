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
  //cin.tie(0);ios::sync_with_stdio(false);
  double a, b, x;
  cin >> a >> b >> x;
  
  double s = x / a;
  double ans = 0;
  if (s > (a * b / 2)) {
    double h = 2 * (a * b - s) / a;
    ans = atan2(h, a) / acos(-1) * 180;
  } else {
    double hh = 2 * (x / (a * b));
    ans = atan2(b, hh) / acos(-1) * 180;
  }
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}
