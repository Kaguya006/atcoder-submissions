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
  string s;
  cin >> s;

  vector<int> W(1e5 * 5);
  vector<int> E(1e5 * 5);
  for (int i = 1; i < n; i++) {
    W[i] = W[i - 1];
    if (s[i - 1]  == 'W') {
      ++W[i];
    }
  }
  for (int i = n - 1; i > 0; i--) {
    E[i - 1] = E[i];
    if (s[i]  == 'E') {
      ++E[i - 1];
    }
  }

  //for (int i = 0; i < n; i++) {
  //  cout << W[i];
  //}
  //cout << endl;
  //for (int i = 0; i < n; i++) {
  //  cout << E[i];
  //}
  //cout << endl;

  int ans = 1e6;
  for (int i = 0; i < n; i++) {
    ans = min(ans, (W[i] + E[i]));
  }

  cout << ans << endl;

  return 0;
}
