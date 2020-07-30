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
  string s;
  cin >> s;
  map<char, int> mv;
  for (int i = 0; i < s.size(); i++) {
    mv[s[i]]++;
  }
  int t;
  cin >> t;

  int x = abs(mv['R'] - mv['L']);
  int y = abs(mv['U'] - mv['D']);
  
  if (t == 1) {
    cout << x + y + mv['?'] << endl;
  } else {
    if (x + y - mv['?'] < 0) {
      if ((x + y - mv['?']) % 2 == 0) {
	cout << 0 << endl;
      } else {
	cout << 1 << endl;
      }
    } else {
      cout << x + y - mv['?'] << endl;
    }
  }
  return 0;
}
