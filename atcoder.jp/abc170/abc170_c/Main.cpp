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
  int x, n;
  cin >> x >> n;
  vector<int> dis(102);
  rep(i, 102) dis[i] = abs(x - i);

  rep(i, n) {
    int x;
    cin >> x;
    dis[x] = -1;
  }

  int ans = 1000;
  int ans_idx = 0;
  for (int i = 0; i < dis.size(); i++) {
    if (dis[i] == -1) continue;
    if (ans > dis[i]) {
      ans = dis[i];
      ans_idx = i;
    }
  }
  cout << ans_idx << endl;

  return 0;
}
