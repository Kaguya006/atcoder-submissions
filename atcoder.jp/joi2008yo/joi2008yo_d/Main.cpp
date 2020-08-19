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
  int N, M;
  cin >> M;
  vector<P> ms(M);
  map<P, bool> mn;
  rep (i, M) {
    int x, y;
    cin >> x >> y;
    ms[i] = make_pair(x, y);
  }
  
  cin >> N;
  vector<P> ns(N);  
  rep (i, N) {
    int x, y;
    cin >> x >> y;
    ns[i] = make_pair(x, y);
    mn[make_pair(x, y)] = true;
  }

  rep (i, N) {
    int cnt = 0;
    int dy = ns[i].second - ms[0].second;
    int dx = ns[i].first - ms[0].first;

    rep (j, M) {
      int to_y = dy + ms[j].second;
      int to_x = dx + ms[j].first;
      if (mn.count({to_x, to_y})) {
	cnt++;
      }
    }

    if (cnt == M) {
      cout << dx << " " << dy << endl;
      return 0;
    }
  }

  
  return 0;
}
