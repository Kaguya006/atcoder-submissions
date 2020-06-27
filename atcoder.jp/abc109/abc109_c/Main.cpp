#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a;
  rep (i, n) {
    int p; cin >> p;
    a.push_back(p);
  }
  a.push_back(x);
  sort(a.begin(), a.end());

  vector<int> dis;
  for (int i = 0; i < n; i++) {
    int q = abs(a[i] - a[i + 1]);
    dis.push_back(q);
  }

  for (int i = 1; i < dis.size(); i++) {
    dis[i] = gcd(dis[i], dis[i - 1]);
  }

  cout << dis.back() << endl;

  return 0;
}
