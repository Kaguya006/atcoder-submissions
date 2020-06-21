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
  int n, max;
  cin >> n;
  map<string, int> mp;
  vector<vector<string>> mstr(200010);
  
  rep (i, n) {
    string str;
    cin >> str;
    mstr[mp[str]].push_back(str);
    ++mp[str];
  }

  set<string> ans;
  for (int i = 200010; i >= 0; i--) {
    if (mstr[i].size() != 0) {
      for (auto v : mstr[i]) {
        ans.insert(v);
      }
      break;
    }
  }

  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}
