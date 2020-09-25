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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;
int main() {
  int n; cin >> n;
  string S; cin >> S;
  vector<string> ans;
  ans.push_back("b");
  int i = 0;
  while(ans.back().size() < 100) {
    string ss = ans.back();
    if (i == 0) {
      ans.push_back("a" + ss + "c");
      i++;
    } else if (i == 1) {
      ans.push_back("c" + ss + "a");
      i++;
    } else {
      ans.push_back("b" + ss + "b");
      i = 0;
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    if (S == ans[i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
