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
const ll MAXN = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  int a[100010];
  rep(i, m) {
    int x;
    cin >> x;
    --x;
    a[x] = 1;
  }

  ll dp[100010];
  rep(i, 100010) dp[i] = 0;
  if(a[0] == 0) dp[0] = 1;
  if (a[1] == 0) {
    if (dp[0] == 1) {
      dp[1] = 2;
    } else {
      dp[1] = 1;
    }
  }
  
  for (int i = 2; i < n; i++) {
    if (a[i] == 1) continue;
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] = dp[i] % MAXN;
  }

  cout << dp[n - 1] << endl;

  return 0;
}
