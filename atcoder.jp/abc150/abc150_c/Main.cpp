#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;
int main() {
  int n;
  cin >> n;  
  vector<int> a(n);
  rep (i, n) a[i] = i + 1;
  string s1 = "";
  string s2 = "";
  rep (i, n) {
    int a;
    cin >> a;
    s1 += to_string(a);
  }
  rep (i, n) {
    int a;
    cin >> a;
    s2 += to_string(a);
  }
  
  vector<string> strs;
  do {
    string s = "";
    for (auto v : a) {
      s += to_string(v);
    }
    strs.push_back(s);
  } while (next_permutation(a.begin(), a.end()));

  int dis1 = find(strs.begin(), strs.end(), s1) - strs.begin();
  int dis2 = find(strs.begin(), strs.end(), s2) - strs.begin();
  cout << abs(dis1 - dis2) << endl;

  return 0;
}
