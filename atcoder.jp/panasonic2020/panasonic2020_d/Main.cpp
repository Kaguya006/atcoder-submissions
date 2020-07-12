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
set<string> ans;

void dfs(string str, char maxch) {
  if (str.size() == n) {
    cout << str << endl;
    return;
  }

  for (char ch = 'a'; ch <= maxch; ch++) {
    if (ch == maxch) dfs(str + ch, maxch + 1);
    else dfs(str + ch, maxch);
  }
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> n;
  dfs("", 'a');
  return 0;
}
