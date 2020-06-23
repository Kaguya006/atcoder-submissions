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
  string s, t;
  cin >> s >> t;

  bool ok = true;
  vector<char> exchar = { 'a', 't','c','o','d','e','r'};
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '@' && t[i] == '@') continue;
    if (s[i] != t[i]) {
      if (s[i] == '@' && find(exchar.begin(), exchar.end(), t[i]) != exchar.end()) continue;
      if (t[i] == '@' && find(exchar.begin(), exchar.end(), s[i]) != exchar.end()) continue;
      ok = false;
    }
  }

  if (ok) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }
  return 0;
}
