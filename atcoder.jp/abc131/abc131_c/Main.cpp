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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  ll q = a % b;

  return gcd(b, q);
}

int main() {
  ll a, b, c, d;
  vector<int> nums;
  cin >> a >> b >> c >> d;
  nums.push_back(c);
  nums.push_back(d);
  ll ex = (c / gcd(max(c, d), min(c, d)) * d);

  ll cnt = 0;
  for (auto x : nums) {
    ll p; 
    if (a < x) {
      p = x;
    } else if (a % x == 0) {
      p = a;
    } else {
      ll r = a % x;
      p = a - r + x;
    }
    if (p == b) {
      ++cnt;
      continue;
    } else if (p > b) {
      continue;
    }
    ll dis = (b - (p + 1) + 1);
    cnt += (dis / x) + 1;
  }

  ll excnt = 0;
  ll p;
  if (a < ex) {
    p = ex;
  } else if (a % ex == 0) {
    p = a;
  } else {
    ll r = a % ex;
    p = a - r + ex;
  }
  if (p == b) {
    ++excnt;
    cout << (b - a + 1) - cnt + excnt << endl;
    return 0;
  } else if (p > b) {
    cout << (b - a + 1) - cnt << endl;
    return 0;
  }
  ll dis = (b - (p + 1) + 1);
  excnt += (dis / ex) + 1;

  cout << (b - a + 1) - cnt + excnt << endl;

  return 0;
}
