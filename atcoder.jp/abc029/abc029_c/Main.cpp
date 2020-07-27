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

int n;
vector<string> ans;

void dfs(string s) {
  if (s.size() == n) {
    ans.push_back(s);
    return;
  }
  
  dfs(s + 'a');
  dfs(s + 'b');
  dfs(s + 'c');
}


//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> n;
  dfs("");
  for (auto v : ans) {
    cout << v << endl;
  }
  
  return 0;
}
