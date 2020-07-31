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

int N, K;
map<int, int> D;
set<int> price;

void dfs(string total) {
  if (total.size() == 6) return;
  
  price.insert(atoi(total.c_str()));

  for (auto v : D) {
    if (v.second) {
      dfs(total + to_string(v.first));
    }
  }
  
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  cin >> N >> K;
  for (int i = 0; i <= 9; i++) D[i] = 1;
  rep (i, K) {
    int x;
    cin >> x;
    D[x] = 0;
  }

  dfs("");

  for (auto v : price) {
    if (v >= N) {
      cout << v << endl;
      return 0;
    }
  }

  
  return 0;
}
