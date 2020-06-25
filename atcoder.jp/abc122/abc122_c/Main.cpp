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
  int n, q;
  cin >> n >> q;
  string str;
  cin >> str;

  vector<int> s(n + 1);
  s[0] = s[1] = 0;
  for (int i = 1; i < n; i++) {
    s[i + 1] = s[i];
    if (str[i - 1] == 'A' && str[i] == 'C') ++s[i + 1];
  }

  vector<int> ans;
  rep (i, q) {
    int l, r;
    cin >> l >> r;
    ans.push_back(s[r] - s[l]);
  }

  for (auto v : ans) {
    cout << v << endl;
  }

  return 0;
}
