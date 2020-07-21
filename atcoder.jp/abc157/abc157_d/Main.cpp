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

vector<vector<int>> fri(100005);
vector<vector<int>> blo(100005);

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  rep (i, m) {
    int a, b;
    cin >> a >> b;
    fri[a].push_back(b);
    fri[b].push_back(a);
  }

  rep (i, k) {
    int c, d;
    cin >> c >> d;
    blo[c].push_back(d);
    blo[d].push_back(c);
  }

  vector<int> group(100005);
  map<int, int> mi;
  for (int i = 1; i <= n; i++) {
    if (group[i] == 0) {
      queue<int> qi;
      qi.push(i);
      group[i] = i;
      mi[i]++;
      while (!qi.empty()) {
	int now = qi.front();
	qi.pop();
	for (auto next_v : fri[now]) {
	  if (group[next_v] == 0) {
	    group[next_v] = i;
	    mi[i]++;
	    qi.push(next_v);
	  }
	}
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int ans = 0;
    ans += mi[group[i]] - (1+ fri[i].size());
    for (auto v : blo[i]) {
      if (group[i] == group[v]) ans--;
    }
    cout << ans << " ";
  }
  cout << endl;

  //printVec(group);
  return 0;
}
