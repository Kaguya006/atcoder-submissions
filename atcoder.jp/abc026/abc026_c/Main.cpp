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
vector<vector<int>> G(21);
vector<int> Emp(21);

int dfs(int now) {
  vector<int> salary;
  if (G[now].size() == 0) return 1;
  if (G[now].size() == 1) return dfs(G[now][0]) * 2 + 1
			    ;
  for (auto next_v : G[now]) {
    salary.push_back(dfs(next_v));
  }
  Emp[now] += *max_element(salary.begin(), salary.end());
  Emp[now] += *min_element(salary.begin(), salary.end());
  Emp[now] += 1;

  return Emp[now];
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int b;
    cin >> b;
    G[b].push_back(i);
  }

  cout << dfs(1) << endl;

  
  return 0;
}
