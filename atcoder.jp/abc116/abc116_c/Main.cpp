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

vector<int> a(100);
int ans = 0;

void sol() {
  bool skip = false;
  for (int i = 0; i < 100; i++) {
    if (a[i] <= 0) {
      skip = false;
      while (a[i] <= 0) ++i;
      if (i >= 100) break;
    }
    if (!skip) {
      skip = true;
      ++ans;
    }
  }
}

void water() {
  for (int i = 0; i < a.size(); i++) --a[i];
}

bool ok() {
  for (auto v : a) if (v > 0) return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> a[i];
  while (!ok()) {
    sol();
    water();
  }
  cout << ans << endl;
}
