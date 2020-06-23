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
  cin.tie(0); ios::sync_with_stdio(false);
  vector<char> alp;
  for (char c = 'a'; c <= 'z'; c++) alp.push_back(c);

  int n;
  cin >> n;
  vector<vector<int>> varifi(n, vector<int>(100));
  map<string, ll> mis;
  rep(i, n) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      auto itr = find(alp.begin(), alp.end(), s[j]);
      ++varifi[i][itr - alp.begin()];
    }
    string tmp = "";
    for (int k = 0; k < 26; k++) tmp += to_string(varifi[i][k]);
    ++mis[tmp];
  }

  ll ans = 0;
  for (auto v : mis) {
    if (v.second < 2) continue;
    ans += v.second * (v.second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
