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

void print(vector<vector<int>>& g) {
  for (auto v : g) {
    printVec(v);
  }
  cout << "--------------" << endl;
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> G(h, vector<char>(w));
  vector<vector<int>> dis(h, vector<int>(w));
  vector<P> start_positions;
  rep (i, h) {
    rep (j, w) {
      cin >> G[i][j];
      if (G[i][j] == '.') {
        start_positions.push_back(make_pair(i, j));
      }
    }
  }

  vector<int> py = { 0, 0, 1, -1 };
  vector<int> px = { 1, -1, 0, 0 };
  int ans = 0;
  for (auto v : start_positions) {
    rep (i, h) rep (j, w) dis[i][j] = -1;
    dis[v.first][v.second] = 0;
    queue<P> sts;
    sts.push(v);
    while (!sts.empty()) {
      //print(dis);
      int x, y;
      y = sts.front().first;
      x = sts.front().second;
      sts.pop();

      for (int i = 0; i < 4; i++) {
        int next_y, next_x;
        next_y = y + py[i];
        next_x = x + px[i];
        if (0 <= next_y && 0 <= next_x && next_y < h && next_x < w) {
          if (G[next_y][next_x] == '.' && dis[next_y][next_x] == -1) {
            sts.push(make_pair(next_y, next_x));
            dis[next_y][next_x] = dis[y][x] + 1;
            ans = max(ans, dis[next_y][next_x]);
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
