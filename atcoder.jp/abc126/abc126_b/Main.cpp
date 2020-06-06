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
  string s;
  cin >> s;

  int a = atoi(s.substr(0, 2).c_str());
  int b = atoi(s.substr(2, 2).c_str());

  if (a == 0 && b != 0) {
    if (b > 12) {
      cout << "NA" << endl;
      return 0;
    }
    cout << "YYMM" << endl;
  } else if (a != 0 && b == 0) {
    if (a > 12) {
      cout << "NA" << endl;
      return 0;
    }
    cout << "MMYY" << endl;
  } else {
    if (a == 0 && b == 0 || (a > 12 && b > 12)) {
      cout << "NA" << endl;
      return 0;
    }
    if (a <= 12 && b <= 12) {
      cout << "AMBIGUOUS" << endl;
      return 0;
    }
    if (a > b) {
      cout << "YYMM" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  }

  return 0;
}
