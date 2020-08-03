#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n, m;
  cin >> n >> m;

  if (m < 2) {
    cout << "-1 -1 -1" << endl;
    return 0;
  }

  map<char, int> mci;
  mci['a'] = 0;
  mci['b'] = 0;
  mci['c'] = 0;
  if (m & 1) {
    m -= 3;
    if (n <= 0) {
      cout << "-1 -1 -1" << endl;
      return 0;
    }
    n -= 1;
    mci['b']++;
  }

  int tmp = m / 2;
  mci['a'] += tmp;
  if (n < tmp) {
    mci['a'] -= (4 * (tmp - n)) / 2;
    mci['c'] += (tmp - n);
  } else if (n > tmp) {
    cout << "-1 -1 -1" << endl;
    return 0;
  }

  bool ng = false;
  for (auto v : mci) {
    if (v.second < 0) ng = true;
  }

  if (ng) {
    cout << "-1 -1 -1" << endl;
    return 0;
  }

  for (auto v : mci) {
    cout << v.second  << " ";
  }
  cout << endl;
  return 0;
}
