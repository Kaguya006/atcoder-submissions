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
  double n;
  int k;
  cin >> n >> k;
  ll total = 0;
  vector<double> p(n);
  for (int i = 1; i <= n; i++) {
    int c_t = 0;
    int v = i;
    while (v <= k - 1) {
      v *= 2;
      ++c_t;
    }
    p[i - 1] = (1 / n * pow(0.5, c_t));
  }

  double ans = 0;
  for (double d : p) {
    ans += d;
  }

  cout << fixed << setprecision(15) <<  ans << endl;

  return 0;
}
