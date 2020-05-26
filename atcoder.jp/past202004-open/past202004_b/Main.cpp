#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
using namespace std;
using P = pair<int,int>;
using ll = long long;

//Get the highest value and key from a map.
template<typename KeyType, typename ValueType> 
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}

int main() {
  string s;
  cin >> s;

  map<char, int> mp;
  mp.insert(make_pair('a', 0));
  mp.insert(make_pair('b', 0));
  mp.insert(make_pair('c', 0));

  for (int i = 0; i < s.size(); i++) {
    ++mp.at(s[i]);
  }

  auto max = get_max(mp);
  cout << max.first << endl;

  return 0;
}
