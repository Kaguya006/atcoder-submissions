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

int n, digit;
vector<string> ans;

void dfs(string a) {
  if (a.size() == digit + 1) return;
  int seven, five,  three;
  five = 0; seven = 0; three = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '7') seven++;
    if (a[i] == '5') five++;
    if (a[i] == '3') three++;
  }
  if (seven != 0 && five != 0 && three != 0 && atoi(a.c_str()) <= n) {
    ans.push_back(a);
  }

  dfs(a + "7");
  dfs(a + "5");
  dfs(a + "3");
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> n;
  digit = to_string(n).size();
  dfs("");

  cout << ans.size() << endl;

  //for (auto v : ans) {
  //  cout << v << endl;
  //}
  
  return 0;
}
